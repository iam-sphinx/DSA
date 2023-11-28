/* Problem Statement -
    You are given a sorted array 'arr' of distinct values and a target value 'm'. You need to search for the index of the target value in the
    array.

    If the value is present in the array, then return its index.
    If the value is not present. Determine the index where it would be inserted in the array while maintaining the sorted order.
        Example :
            input : arr=[1, 2, 4, 7], m = 6
            output : 3
        Explanation : If the given array 'arr' is : [1, 2, 4, 7] and m = 6. We insert m = 6 in the array and get 'arr' as : [1, 2, 4, 6, 7].
        The position of 6 is 3 (according to 0-based indexing).
*/
#include <iostream>
#include <vector>
using namespace std;

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

    int idx = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (input[mid] >= find)
        {
            idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "correct place for" << find << " is : " << idx << endl;
    return 0;
}

/* Similar problem : find floor and ceil in sorted array
    solution : Floor value => larget no in array <= x
               Ceil value => smallest no in array >= x (lower bound) */