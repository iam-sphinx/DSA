/*You are given n balloons, startexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to
 burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then
treat it as if there is a balloon with a 1 painted on it.*/

/*
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Solution
int recSolve(vector<int> &input, int start, int end)
{
    if (start > end)
    {
        return 0;
    }
    int maxi = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        int cost = input[start - 1] * input[i] * input[end + 1] + recSolve(input, start, i - 1) + recSolve(input, i + 1, end);
        maxi = max(maxi, cost);
    }
    return maxi;
}

// Memoization Solution
int memoSolve(vector<int> &input, int start, int end, vector<vector<int>> &dp)
{
    if (start > end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int maxi = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        int cost = input[start - 1] * input[i] * input[end + 1] + memoSolve(input, start, i - 1, dp) + memoSolve(input, i + 1, end, dp);
        maxi = max(maxi, cost);
    }
    return dp[start][end] = maxi;
}

// Tabulation Solution
int tabSolve(vector<int> &input, int start, int end, vector<vector<int>> &dp)
{
    // base case covered in dp initialization
    for (int i = end; i >= start; i--)
    {
        for (int j = start; j <= end; j++)
        {
            if(i > j)
            {
                continue;
            }
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int cost = input[i - 1] * input[k] * input[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[start][end];
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
    input.insert(input.begin(), 1);
    input.insert(input.end(), 1);
    // Recusive Approach
    int recAns = recSolve(input, 1, n);
    cout << "Recursive Solution : " << recAns << endl;

    // Memoization Approach
    vector<vector<int>> memoDP(n + 1, vector<int>(n + 1, -1));
    int memoAns = memoSolve(input, 1, n, memoDP);
    cout << "Memoization Solution : " << memoAns << endl;

    // Tabulation Approach
    vector<vector<int>> tabDP(n + 2, vector<int>(n + 2, 0));
    int tabAns = tabSolve(input, 1, n, tabDP);
    cout << "Tabulation Solution : " << tabAns << endl;
}
