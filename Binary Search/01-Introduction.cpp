/*  BINARY SEARCH
 *  Real life example
 *  Coding problem example
 *  Iterative code
 *  Recursive  Code
 *  Time Complexity
 *  Overflow Case
 */
#include <bits/stdc++.h>
using namespace std;

int bSearch(vector<int> &input, int find)
{
    int low = 0;
    int high = input.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (input[mid] == find)
        {
            return mid;
        }
        else if (input[mid] > find)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int recBsearch(vector<int> &input, int find, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (input[mid] == find)
    {
        return mid;
    }
    if (input[mid] > find)
    {
        return recBsearch(input, find, low, mid - 1);
    }
    return recBsearch(input, find, mid + 1, high);
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
    sort(input.begin(), input.end());
    int idx = bSearch(input, find);
    cout << idx << endl;

    int recIdx = recBsearch(input, find, 0, n - 1);
    cout << recIdx << endl;
}