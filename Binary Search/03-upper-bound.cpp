/* upper Bound - smallest index such that arr[idx] > x */

#include <iostream>
#include <vector>
using namespace std;

void recBsearch(vector<int> &input, int &upperBound, int find, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int mid = (low + high) / 2;
    if (input[mid] > find)
    {
        upperBound = mid;
        recBsearch(input, upperBound, find, low, mid - 1);
    }
    else
    {
        recBsearch(input, upperBound, find, mid + 1, high);
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
    int upperBound = n;
    recBsearch(input, upperBound, find, 0, n - 1);
    cout << "Lower bound : " << upperBound << endl;
}