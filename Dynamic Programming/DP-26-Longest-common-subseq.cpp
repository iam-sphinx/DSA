/*Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence, i.e. longest subsequence present in both of
the strings.

A longest common subsequence (LCS) is defined as the longest subsequence which is common in all given input sequences.*/

#include <iostream>
#include <vector>
using namespace std;

int lcs(string &s1, string &s2, int n, int m)
{
    if (n < 0 || m < 0)
        return 0;

    if (s1[n] == s2[m])
    {
        return (1 + lcs(s1, s2, n - 1, m - 1));
    }
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

int memoLcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n] == s2[m])
    {
        return dp[n][m] = 1 + memoLcs(s1, s2, n - 1, m - 1, dp);
    }
    return dp[n][m] = max(memoLcs(s1, s2, n - 1, m, dp), memoLcs(s1, s2, n, m - 1, dp));
}

// Tabulation Solution
int tabSolve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    // base case
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // Bottom Up
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> memoDP(n, vector<int>(m, -1));
        vector<vector<int>> tabDP(n + 1, vector<int>(m + 1, 0));
        int recAns = lcs(s1, s2, n - 1, m - 1);
        cout << "Recursive solution : " << recAns << endl;

        int memoAns = memoLcs(s1, s2, n - 1, m - 1, memoDP);
        cout << "Memoization Solution : " << memoAns << endl;

        int tabans = tabSolve(s1, s2, n, m, tabDP);
        cout << "Tabulation solution : " << tabans << endl;

        // printing the LCS
        string output = "";
        int len = tabDP[n][m];

        // Initialize the output string with empty characters
        for (int i = 0; i < n; i++)
        {
            output += " ";
        }

        int idx = len;
        int i = n, j = m;

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                output[idx - 1] = s1[i - 1];
                i--;
                j--;
                idx--;
            }
            else
            {
                if (tabDP[i - 1][j] > tabDP[i][j - 1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }

        cout << "Longest Common Subsequence : " << output << endl;
    }
}