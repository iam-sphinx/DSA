/*  Solve a problem in a pattern */

// Matrix Chain Multiplication

#include <iostream>
#include <vector>
using namespace std;

int recSolve(vector<int> &input, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = (input[i - 1] * input[k] * input[j]) + recSolve(input, i, k, dp) + recSolve(input, k + 1, j, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int recAns = recSolve(input, 1, n - 1, dp);
    cout << "Recursive Solution : " << recAns << endl;
}
