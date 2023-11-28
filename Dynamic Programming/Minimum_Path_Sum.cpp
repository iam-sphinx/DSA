/* Ninjaland is a country in the shape of a 2D grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost
associated with it.

Find a path from top left i.e (0,0) to the bottom right i.e (n - 1)(m - 1) which minimizes the sum of the cost of all numbers
along the path. You need to tell the minimum sum of that path.

NOTE : You can only move right or down

*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int recSolve(int m, int n, vector<vector<int>> &GRID)
{
    if (m == 0 && n == 0)
        return GRID[0][0];

    if (m < 0 || n < 0)
        return 1e9;

    int left = GRID[m][n] + recSolve(m, n - 1, GRID);
    int up = GRID[m][n] + recSolve(m - 1, n, GRID);
    int result = min(left, up);
    return result;
}

// memoization approach
int memoSolve(int m, int n, vector<vector<int>> &GRID, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return GRID[0][0];

    if (m < 0 || n < 0)
        return 1e9;

    // dp
    if (dp[m][n] != -1)
        return dp[m][n];

    int left = GRID[m][n] + memoSolve(m, n - 1, GRID, dp);
    int up = GRID[m][n] + memoSolve(m - 1, n, GRID, dp);

    dp[m][n] = min(left, up);
    return dp[m][n];
}

// tabulation approach
int tabSolve(int m, int n, vector<vector<int>> &GRID, vector<vector<int>> &dp)
{
    for (int row = 0; row <= m; row++)
    {
        for (int col = 0; col <= n; col++)
        {
            if (row == 0 && col == 0)
            {
                dp[row][col] = GRID[row][col];
            }
            else
            {
                int left = 1e9; // Initialize to a large value
                int up = 1e9;   // Initialize to a large value

                if (col > 0)
                {
                    left = dp[row][col - 1] + GRID[row][col];
                }
                if (row > 0)
                {
                    up = dp[row - 1][col] + GRID[row][col];
                }

                dp[row][col] = min(up, left);
            }
        }
    }
    return dp[m][n];
}

// space optimization
int spaceOptSolve(int m, int n, vector<vector<int>> &GRID)
{
    vector<int> prev(n+1, 0);

    for (int row = 0; row <= m; row++) // Update the loop condition
    {
        vector<int> curr(n+1, 0);
        for (int col = 0; col <= n; col++) // Update the loop condition
        {
            if (row == 0 && col == 0)
            {
                curr[col] = GRID[row][col];
            }
            else
            {
                int left = 1e9;
                int up = 1e9;
                if (row > 0)
                {
                    up = GRID[row][col] + prev[col];
                }
                if (col > 0)
                {
                    left = GRID[row][col] + curr[col - 1];
                }
                curr[col] = min(left, up);
            }
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> GRID(m, vector<int>(n, 0));
    vector<vector<int>> memoDp(m, vector<int>(n, -1));
    vector<vector<int>> tabDp(m, vector<int>(n, -1));

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> GRID[row][col];
        }
    }
    int recAns = recSolve(m - 1, n - 1, GRID);
    cout << "Recursive ans : " << recAns << endl;
    int memoAns = memoSolve(m - 1, n - 1, GRID, memoDp);
    cout << "Memoization ans : " << memoAns << endl;
    int tabAns = tabSolve(m - 1, n - 1, GRID, tabDp);
    cout << "Tabulation ans : " << tabAns << endl;
    int spaceOptAns = spaceOptSolve(m - 1, n - 1, GRID);
    cout << "Space optimized ans : " << spaceOptAns << endl;
}