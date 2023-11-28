/*Given two strings, S1 and S2, the task is to find the length of the Longest Common Substring, i.e. longest substring present in both of
the strings.

A longest common substring (LCS) is defined as the longest substring which is common in all given input sequences.*/

#include <iostream>
#include <vector>
using namespace std;





// Tabulation Solution
int tabSolve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp, string &output)
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
    int max_val = INT_MIN;
    // Bottom Up
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                max_val = max(max_val , dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return max_val;
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
        string output;
        vector<vector<int>> memoDP(n, vector<int>(m, -1));
        vector<vector<int>> tabDP(n + 1, vector<int>(m + 1, 0));
        int tabans = tabSolve(s1, s2, n, m, tabDP, output);
        cout << "Tabulation solution : " << tabans << endl;

    }
}