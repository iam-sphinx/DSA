/* Longest Increasing Subequence */
/* Array => [10, 9, 2, 5, 3, 7, 101, 18]*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int recSolve(vector<int> &input, int idx, int prev_idx)
{
    if (idx >= input.size())
    {
        return 0;
    }
    int take = 0;
    if (prev_idx == -1 || input[idx] > input[prev_idx])
    {
        take = 1 + recSolve(input, idx + 1, idx);
    }
    int nottake = 0 + recSolve(input, idx + 1, prev_idx);
    return max(take, nottake);
}

// Memoization Solution
int memoSolve(vector<int> &input, int idx, int prev_idx, vector<vector<int>> &dp)
{
    if(idx >= input.size())
    {
        return 0;
    }
    if(dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }

    int take = 0;
    if(prev_idx == -1 || input[idx] > input[prev_idx])
    {
        take = 1 + memoSolve(input, idx + 1, idx, dp);
    }
    int nottake = 0 + memoSolve(input, idx + 1, prev_idx, dp);
    return dp[idx][prev_idx + 1] = max(take, nottake);
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
    int recAns = recSolve(input, 0, -1);
    cout << "Recursive Solution : " << recAns << endl;

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int memoAns = memoSolve(input, 0, -1, dp);
    cout << "Memoization Solution : " << memoAns << endl;
}