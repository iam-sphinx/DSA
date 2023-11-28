/*

 Problem statement - You are given an array of nos and you need to find out maximum sum of subsequence but keep in mind you can not take two
 adjacent elements together.

 */

#include <bits/stdc++.h>
using namespace std;

// first i am gonna try recursive way later memoiazation and tabulation stuff.
int recSolve(vector<int> &input, int idx)
{
    if (idx == 0) // think of this case as i am on idx 0 that means i havent taken idx 1 so need to take that to maximize. think that way.
    {
        return input[idx]; // should i just return the element at idx==0;
    }
    // another edge case
    if (idx < 0)
    {
        return 0; // here i am accesing out of bound idx so nothing there so 0
    }

    // if i am taking it
    int taken = input[idx] + recSolve(input, idx - 2); // look i am going 2 index down to ensure no adjacent element be a part.
    // if not going to take it.
    int notTaken = 0 + recSolve(input, idx - 1);

    // now as of result taking max of both cases
    int res = max(taken, notTaken);
    return res;
}

// memoization solution dp
int memoSolve(vector<int> &input, vector<int> &dp, int idx)
{
    if (idx == 0)
    {
        return input[idx];
    }

    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];

    int taken = input[idx] + memoSolve(input, dp, idx - 2);
    int notTaken = 0 + memoSolve(input, dp, idx - 1);
    return dp[idx] = max(taken, notTaken);
}

int tabSolve(vector<int> &input, vector<int> &dp, int idx)
{
    dp[0] = input[0];

    for (int i = 1; i <= idx; i++)
    {
        int taken;
        int notTaken;

        taken = input[i];
        if (i > 1)
            taken += dp[i - 2];
        notTaken = 0 + dp[i - 1];

        dp[i] = max(taken, notTaken);
    }

    return dp[idx];
}

// Space optimised answer
int spOptSolve(vector<int>&input, int idx)
{
    int prev2 = 0;
    int prev = input[0];
    for(int i=1; i<=idx; i++)
    {
        int taken = input[i];
        int notTaken;
        if(i > 1)
        taken += prev2;
        notTaken = 0 + prev;

        int cur = max(taken, notTaken);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    // for dp;
    vector<int> dp(n + 1, -1);
    vector<int> tabDp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int recAns = recSolve(input, n - 1);
    cout << "Simple recursive solution: " << recAns << endl;
    int memoAns = memoSolve(input, dp, n - 1);
    cout << "Memoization DP solution: " << memoAns << endl;
    int tabAns = tabSolve(input, tabDp, n - 1);
    cout << "Tabulatio DP solution: " << tabAns << endl;
    int spOpt = spOptSolve(input, n-1);
    cout<<"Space optimised solution: "<<spOpt<<endl;
}