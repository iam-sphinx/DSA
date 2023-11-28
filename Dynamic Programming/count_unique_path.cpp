/* You are present on pont 'A' which is the top-left cell of on M x N matrix, your destination is point 'B'. Which is the bottom right cell of the same matrix.
Your task is to find the total number of unique paths from point 'A' to point 'B'. In other words, you will be given the dimensions of the matrix as integers
'M' and 'N', your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX[M - 1][N - 1].

To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i][j]. you can move to either MATRIX[i + 1][j]
or MATRIX[i][j + 1] */

#include <iostream>
#include <vector>
using namespace std;

// recursive approach
int recSolve(int m, int n)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    int upDirection = recSolve(m - 1, n);
    int leftDirection = recSolve(m, n - 1);

    return (upDirection + leftDirection);
}

// memoization solution
int memoSolve(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int upDirection = memoSolve(m - 1, n, dp);
    int leftDirection = memoSolve(m, n - 1, dp);

    dp[m][n] = upDirection + leftDirection;

    return dp[m][n];
}

int tabSolve(int m, int n, int right, int down, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue; // as it is our base case already covered
            }
            int upDirection = 0;
            int leftDirection = 0;
            if (i > 0)

                upDirection = dp[i - 1][j];
            if (j > 0)
                leftDirection = dp[i][j - 1];

            dp[i][j] = upDirection + leftDirection;
        }
    }
    return dp[m][n];
}

int main()
{
    int m, n;
    cout << "enter matrix dimensions : " << endl;
    cin >> m >> n;

    vector<vector<int>> memoDp(m, vector<int>(n, -1)), tabDp(m, vector<int>(n, -1));

    int recResult = recSolve(m - 1, n - 1);
    cout << " Recursive result : " << recResult << endl;
    int memoResult = memoSolve(m - 1, n - 1, memoDp);
    cout << " Memoization result : " << memoResult << endl;
    int tabResult = tabSolve(m - 1, n - 1, 0, 0, tabDp);
    cout << " Tabulation result : " << tabResult << endl;
}