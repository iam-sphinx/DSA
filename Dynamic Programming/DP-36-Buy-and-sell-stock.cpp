/*You are given an array of costs at different days. You have to buy a stock and can sell at any day. you have to return maximum profit you
can earn*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int recSolve(vector<int> &days, int idx, bool canBuy)
{
    if (idx == days.size())
    {
        return 0;
    }
    int profit;

    if (canBuy)
    {
        profit = max(-days[idx] + recSolve(days, idx + 1, false), recSolve(days, idx + 1, true));
    }
    else
    {
        profit = max(days[idx] + recSolve(days, idx + 1, true), recSolve(days, idx + 1, false));
    }
    return profit;
}

// Memoization Approach
int memoSolve(vector<int> &days, int idx, bool canBuy, vector<vector<int>> &dp)
{
    if (idx == days.size())
    {
        return 0;
    }
    int profit;

    if (dp[idx][canBuy] != -1)
    {
        return dp[idx][canBuy];
    }

    if (canBuy)
    {
        profit = max(-days[idx] + memoSolve(days, idx + 1, false, dp), memoSolve(days, idx + 1, true, dp));
    }
    else
    {
        profit = max(days[idx] + memoSolve(days, idx + 1, true, dp), memoSolve(days, idx + 1, false, dp));
    }
    return dp[idx][canBuy] = profit;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> memoDp(n, vector<int>(2, -1));
    vector<int> days(n);
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }
    bool buy = true;

    int recAns = recSolve(days, 0, buy);
    cout << "Recurive Solution : " << recAns << endl;

    int memoAns = memoSolve(days, 0, buy,memoDp);
    cout << "Memoization Solution : " << memoAns << endl;
}