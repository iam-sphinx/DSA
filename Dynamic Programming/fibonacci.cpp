// It is memoization method which is top down i.e required case to base case

#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n);
// Space complexity - O(n) + O(n);  for array and stack space;
  
int solve(int fib, vector <int> &dp)
{
    if (fib <= 1)
    {
        return fib;
    }

    if (dp[fib] != -1)
        return dp[fib];

    dp[fib] = solve(fib - 1, dp) + solve(fib - 2, dp);
    return (dp[fib]);
}

int main()
{
    int n;
    cin >> n;
    // int dp[n + 1];
    // memset(dp, -1, sizeof(dp));

    vector<int> dp(n + 1, -1);
    int ans = solve(n, dp);
    cout << ans;
}