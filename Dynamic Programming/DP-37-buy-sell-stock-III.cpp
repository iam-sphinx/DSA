/* BEST TIME TO BUY AND SELL THE STOCKS III AT MAX TWO TRANSACTIONS */
/* prices = [3, 3, 5, 0, 0, 3, 1, 4]*/
#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int recSolve(vector<int> &input, int i, bool canBuy, int cap)
{
    if (i < 0)
    {
        return 0;
    }
    if (cap == 0)
    {
        return 0;
    }
    int maxProfit = -1e8;
    if (canBuy)
    {
        int buy = -input[i] + recSolve(input, i - 1, false, cap);
        int notbuy = 0 + recSolve(input, i - 1, true, cap);
        maxProfit = max(buy, notbuy);
    }
    else
    {
        int sell = input[i] + recSolve(input, i - 1, true, cap - 1);
        int notsell = 0 + recSolve(input, i - 1, false, cap);
        maxProfit = max(sell, notsell);
    }
    return maxProfit;
}

// Memoization Approach
int memoSolve(vector<int> &input, int i, bool canBuy, int cap, vector<vector<vector<int>>> &dp)
{

    if (i < 0)
    {
        return 0;
    }
    if (cap == 0)
    {
        return 0;
    }
    if (dp[i][canBuy][cap] != -1)
    {
        return dp[i][canBuy][cap];
    }
    int maxProfit = -1e8;
    if (canBuy)
    {
        int buy = -input[i] + memoSolve(input, i - 1, false, cap, dp);
        int notbuy = 0 + memoSolve(input, i - 1, true, cap, dp);
        maxProfit = max(buy, notbuy);
    }
    else
    {
        int sell = input[i] + memoSolve(input, i - 1, true, cap - 1, dp);
        int notsell = 0 + memoSolve(input, i - 1, false, cap, dp);
        maxProfit = max(sell, notsell);
    }
    return dp[i][canBuy][cap] = maxProfit;
}

// Tabulation Approach
int tabSolve(vector<int> &input, int n,bool canBuy, int cap, vector<vector<vector<int>>> &dp)
{

    for (int k = 1; k <= n; k++)
    {
        for (int l = 0; l < 2; l++)
        {
            for (int m = 1; m <= cap; m++)
            {
                if (l == 0)
                {
                    int buy = -input[k - 1] + dp[k - 1][1][m];
                    int notbuy = dp[k - 1][0][m];
                    dp[k][l][m] = max(buy, notbuy);
                }
                else
                {
                    int sell = input[k - 1] + dp[k - 1][0][m - 1];
                    int notsell = dp[k - 1][1][m];
                    dp[k][l][m] = max(sell, notsell);
                }
            }
        }
    }
    return dp[n][0][cap];
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
    int cap = 2;
    bool canBuy = true;

    // Recursion
    int recAns = recSolve(input, n - 1, canBuy, cap);
    cout << "Recursive Approach Solution : " << recAns << endl;

    // memoization
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    int memoAns = memoSolve(input, n - 1, canBuy, cap, dp);
    cout << "Memoization Approach Solution : " << memoAns << endl;

    // Tabulation
    vector<vector<vector<int>>> dp1(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    int tabAns = tabSolve(input, n - 1, canBuy, cap, dp1);
    cout << "Tabulation Approach Solution : " << tabAns;
}
