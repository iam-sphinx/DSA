/* Given a 'N' x 'M' maze with obstacles, count and return the number of paths to reach the right bottm of the cell from the top left cell.
 A cell in the given maze has a value -1 if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1,j)
and (i,j+1) only. Since the answer can be large, print it modulo 10^9 + 7

consider the maze below :

0  0  0
0 -1  0
0  0  0

output : 2
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int recSolve(int m, int n, vector<vector<int>> &maze)
{
    // base case
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (m >= 0 && n >= 0 && maze[m][n] == -1)
        return 0;

    // recursion
    int leftDirection = recSolve(m, n - 1, maze);
    int rightDirection = recSolve(m - 1, n, maze);

    return (leftDirection + rightDirection);
}

// Memoization Approach
int memoSolve(int m, int n, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    // base case
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (m >= 0 && n >= 0 && maze[m][n] == -1)
        return 0;

    // dp
    if (dp[m][n] != -1)
        return dp[m][n];

    int leftDirection = memoSolve(m, n - 1, maze, dp);
    int upDirection = memoSolve(m - 1, n, maze, dp);

    dp[m][n] = leftDirection + upDirection;

    return dp[m][n];
}

// Tabulation Approach
int tabSolve(int m, int n, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    // base case
    dp[0][0] = 1;

    for (int row = 0; row <= m; row++)
    {
        for (int col = 0; col <= n; col++)
        {
            if (row == 0 && col == 0)
                continue;

            else if (maze[row][col] == -1)
                dp[row][col] = 0;
            else
            {
                int leftDirection = 0;
                int upDirection = 0;
                if (row > 0)
                    upDirection = dp[row - 1][col];
                if (col > 0)
                    leftDirection = dp[row][col - 1];

                dp[row][col] = leftDirection + upDirection;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    int m, n;
    cout << "enter the dimensions of matrix : " << endl;
    cin >> m >> n;

    vector<vector<int>> maze(m, vector<int>(n, 0));
    vector<vector<int>> memoDp(m, vector<int>(n, -1));
    vector<vector<int>> tabDp(m, vector<int>(n, 0));

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> maze[row][col];
        }
    }

    int recAns = recSolve(m - 1, n - 1, maze);
    cout << "recursive solution : " << recAns << endl;
    int memoAns = memoSolve(m - 1, n - 1, maze, memoDp);
    cout << "memoization solution : " << memoAns << endl;
    int tabAns = tabSolve(m - 1, n - 1, maze, tabDp);
    cout << "Tabulation solution : " << tabAns << endl;
}
