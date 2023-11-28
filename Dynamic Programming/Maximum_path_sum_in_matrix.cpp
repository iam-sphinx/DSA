/*You have been given an N * M matrix GRID filled with integer numbers. Find the maximum sum that can be obtained from a path starting from any cells in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col). we can move in three directions i.e.

up : [row + 1, col]
up Left Diagonal : [row + 1, col - 1]
up Right Diagonal : [row + 1, col + 1]
*/

#include <iostream>
#include <vector>

using namespace std;

// TC -> O(3^n)     EXPONENTIAL !
// SC -> O(n)
//  recursive solution
int recSolve(vector<vector<int>> &GRID, int row, int col)
{
    if (row == 0)
    {
        return GRID[row][col];
    }

    int result = INT_MIN;
    for (int i = 0; i <= col; i++)
    {
        int left = INT_MIN;
        int right = INT_MIN;
        int up = GRID[row][i] + recSolve(GRID, row - 1, i);
        if (i > 0)
            left = GRID[row][i] + recSolve(GRID, row - 1, i - 1);
        if (i < col)
            right = GRID[row][i] + recSolve(GRID, row - 1, i + 1);
        result = max(max(up, result), max(right, left));
    }
    return result;
}

// TC -> O(n*m)
// SC -> O(n*m) + O(n)
//  Memoization Soluiton
int memoSolve(vector<vector<int>> &GRID, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0)
    {
        return GRID[row][col];
    }

    if (dp[row][col] != -1)
        return dp[row][col];

    int result = INT_MIN;
    for (int i = 0; i <= col; i++)
    {
        int left = INT_MIN;
        int right = INT_MIN;
        int up = GRID[row][i] + recSolve(GRID, row - 1, i);
        if (i > 0)
            left = GRID[row][i] + recSolve(GRID, row - 1, i - 1);
        if (i < col)
            right = GRID[row][i] + recSolve(GRID, row - 1, i + 1);
        result = max(max(up, result), max(right, left));
    }

    return dp[row][col] = result;
}

// Tabulation Solution
int tabSolve(vector<vector<int>> &GRID, int row, int col, vector<vector<int>> &dp)
{
    // base case
    for (int i = 0; i <= col; i++)
    {
        dp[0][i] = GRID[0][i];
    }

    // moving till top
    for (int i = 1; i <= row; i++)
    {
        int result = INT_MIN;
        for (int j = 0; j <= col; j++)
        {
            int left = INT_MIN;
            int right = INT_MIN;
            int up = GRID[i][j] + dp[i - 1][j];
            if (j > 0)
                left = GRID[i][j] + dp[i - 1][j - 1];
            if (j < col)
                right = GRID[i][j] + dp[i - 1][j + 1];
            result = max(max(up, result), max(right, left));
            dp[i][j] = result;
        }
    }

    int ans = dp[row][0];

    for (int i = 0; i <= col; i++)
    {
        ans = max(ans, dp[row][i]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> GRID(n, vector<int>(m, 0));
    vector<vector<int>> MemoDp(n, vector<int>(m, -1));
    vector<vector<int>> TabDp(n, vector<int>(m, 0));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            cin >> GRID[row][col];
        }
    }

    int recAns = recSolve(GRID, n - 1, m - 1);
    cout << "Recursive Solution : " << recAns << endl;

    int memoAns = memoSolve(GRID, n - 1, m - 1, MemoDp);
    cout << "Memoization Solution : " << memoAns << endl;

    int tabAns = tabSolve(GRID, n - 1, m - 1, TabDp);
    cout << "Tabulation Solution : " << tabAns << endl;
}
