// first trying to get recursion solution then proceed to dp

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &input, int idx)
{
    if (idx <= 0)
    {
        return 0;
    }

    int left = solve(input, idx - 1) + abs(input[idx] - input[idx - 1]);
    int right = solve(input, idx - 2) + abs(input[idx] - input[idx - 2]);

    int result = min(right, left);
    return result;
}

// now approaching to memoization top down approach
int dpSolve(vector<int> &input, vector<int> &dp, int idx)
{
    if (idx <= 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
        return dp[idx];
    int left = dpSolve(input, dp, idx - 1) + abs(input[idx] - input[idx - 1]);
    int right = dpSolve(input, dp, idx - 2) + abs(input[idx] - input[idx - 2]);

    dp[idx] = min(right, left);
    return dp[idx];
}

// Tabulation Method
int tabSolve(vector<int> &input, vector<int> &dp, int idx)
{
    dp[0] = 0;
    for (int i = 1; i <= idx; i++)
    {
        int left = dp[i - 1] + abs(input[i] - input[i - 1]);
        int right = INT_MAX;

        if (i > 1)
            right = dp[i - 2] + abs(input[i] - input[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[idx];
}

// space optimization
int spaceSolve(vector<int> &input, int idx)
{
    int prev2 = 0;
    int prev = 0;
    int curi = 0;
    for (int i = 1; i <= idx; i++)
    {
        int left = prev + abs(input[i] - input[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
         right = prev2 + abs(input[i] - input[i - 2]);
        }
        curi = min(left, right);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    // making dp for memoization
    vector<int> dp(n + 1, -1);
    // making dp for tabulation
    vector<int> tabDp(n + 1);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    ans = solve(input, n - 1);
    int dpAns = dpSolve(input, dp, n - 1);
    int tabAns = tabSolve(input, tabDp, n - 1);
    int spOpt = spaceSolve(input, n - 1);
    cout << "recursion answer : " << ans << endl;
    cout << "Memoiaztion answer: " << dpAns << endl;
    cout << "Tabulation answer: " << tabAns << endl;
    cout << "Space optimized answer: " << spOpt << endl;
}