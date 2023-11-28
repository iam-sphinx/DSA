/* Lower Bound - smallest index such that arr[idx] >= x */

#include <iostream>
#include <vector>
using namespace std;

void recBsearch(vector<int> &input, int &lowerBound, int find, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int mid = (low + high) / 2;
    if (input[mid] >= find)
    {
        lowerBound = mid;
        recBsearch(input, lowerBound, find, low, mid - 1);
    }
    else
    {
        recBsearch(input, lowerBound, find, mid + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int find;
    cin >> find;
    int lowerBound = n;
    recBsearch(input, lowerBound, find, 0, n - 1);
    cout << "Lower bound : " << lowerBound << endl;
}