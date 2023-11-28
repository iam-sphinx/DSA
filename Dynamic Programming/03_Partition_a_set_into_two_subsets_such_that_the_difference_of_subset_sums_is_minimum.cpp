/* You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subsets sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        totSum += input[i];
    }
    int k = totSum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true; // for each target = 0 all idx shoud be true
    }
    if (input[0] <= k)
        dp[0][input[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (input[ind] <= target)
            {
                take = dp[ind - 1][target - input[ind]];
            }
            dp[ind][target] = take | notTake;
        }
    }

    // dp[n-1][col->0 ... totsum]
    int mini = 1e9;
    for (int s1 = 0; s1 <= totSum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }
    cout << mini << endl;
}