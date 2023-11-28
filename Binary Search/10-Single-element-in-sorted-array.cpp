/*
    Difficulty - Medium
    Topics - Array, Binary Search

    Problem Statement -
        You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears
        exactly once.

        Return the single element that appears only once.

        Your solution must run in O(log n) time and O(1) space.

    Example 1:

        Input: nums = [1,1,2,3,3,4,4,8,8]
        Output: 2

    Example 2:

        Input: nums = [3,3,7,7,10,11,11]
        Output: 10

    Intution - First think you are standing on that index which is single and Try to observe your neighbour elements. In Binary Search we generally
    Eleminate one half which definetely does not contains our ans. So we are gonna element left or right side of array which isn't containing our
    answer. One thing You had observed that for left half follow pattern {odd , even}, {odd, even}, ... and right half follows pattern {even, odd},
    {even, odd}, ... . if we observe indexes. So we gotta our ans we have to check weather it is on right side or left side and eleminate the same

    so when  we are at even index we will check if index - 1 are same => left side eleminate
    else will satisfy right side

*/

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();

    // Edge cases
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        bool flag = mid & 1;

        if ((flag && nums[mid] == nums[mid + 1]) || (!flag && nums[mid] == nums[mid - 1]))
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

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << singleNonDuplicate(input) << endl;
    return 0;
}