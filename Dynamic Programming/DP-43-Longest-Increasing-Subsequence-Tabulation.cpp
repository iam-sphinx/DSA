/* Continuation of DP-43 now Tabulation part */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tabSolve(vector<int> &input, int idx, int prev_idx, vector<vector<int>> &dp)
{
    for (int i = input.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int len = dp[i + 1][j + 1];
            if (j == -1 || input[i] > input[j])
            {
                len = max(len, 1 + dp[i + 1][i + 1]);
            }
            dp[i][j + 1] = len;
        }
    }
    return dp[idx][prev_idx + 1];
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
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int tabAns = tabSolve(input, 0, -1, dp);
    cout << "Tabulation Solution : " << tabAns << endl;

    // optimized approach
    vector<int> dp1(n, 1), hash(n);
    int optAns = 1, last_idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (input[prev] < input[i] && 1 + dp1[prev] > dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
                hash[i] = prev;
            }
        }
        if (dp1[i] > optAns)
        {
            optAns = dp1[i];
            last_idx = i;
        }
    }
    cout << "Optimized Ans : " << optAns << endl;
    vector<int> temp;
    temp.push_back(input[last_idx]);
    while (hash[last_idx] != last_idx)
    {
        last_idx = hash[last_idx];
        temp.push_back(input[last_idx]);
    }
    reverse(temp.begin(), temp.end());
    for(auto x : temp)
    {
        cout<<x<<" ";
    }
}