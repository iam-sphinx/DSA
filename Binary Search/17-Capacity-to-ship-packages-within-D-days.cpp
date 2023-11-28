/*
    Difficulty : Medium
    Topic : Array, Binary Search

    Problem Statement : A conveyor belt has packages that must be shipped from one port to another within days days.

    The ith package on the conveyor belt has a weight of input[i]. Each day, we load the ship with packages on the conveyor belt
    (in the order given by input). We may not load more weight than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

    Example 1:
        Input: input = [1,2,3,4,5,6,7,8,9,10], days = 5
        Output: 15
    Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
        1st day: 1, 2, 3, 4, 5
        2nd day: 6, 7
        3rd day: 8
        4th day: 9
        5th day: 10

    Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like
    (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

    Example 2:
        Input: input = [3,2,2,4,1,4], days = 3
        Output: 6
    Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
        1st day: 3, 2
        2nd day: 2, 4
        3rd day: 1, 4

    Example 3:
        Input: input = [1,2,3,1,1], days = 4
        Output: 3
    Explanation:
        1st day: 1
        2nd day: 2
        3rd day: 3
        4th day: 1, 1

Constraints:
    * 1 <= days <= input.length <= 5 * 104
    * 1 <= input[i] <= 500
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &input, int capacity, int Days)
{
    int day = 1;
    int val = 0;
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        val += input[i];
        if (val > capacity)
        {
            val = input[i];
            day++;
        }
    }
    return day <= Days;
}

int main()
{
    int n, Days;
    cin >> n >> Days;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int low = input[0];
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, input[i]);
        high += input[i];
    }

    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(input, mid, Days))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}