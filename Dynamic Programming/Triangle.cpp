/* You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to bottm row.

The triangle array will have N rows and the i-th row, where 0 < = i < N will have i + 1 elements.

You can move only to the adjacent number of row below each step. For example, if you are ay index j in row i, then you can move
to i or i + 1 index in row j + 1 in each step.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int recSolve(vector<vector<int>> &TRIANGLE, int i, int j, int lastRow)
{
    if (i == lastRow)
        return TRIANGLE[lastRow][j];

    int down = TRIANGLE[i][j] + recSolve(TRIANGLE, i + 1, j, lastRow);
    int diagonal = TRIANGLE[i][j] + recSolve(TRIANGLE, i + 1, j + 1, lastRow);

    return min(down, diagonal);
}

// Memoiazation Approach
int memoSolve(vector<vector<int>> &TRIANGLE, int i, int j, int lastRow, vector<vector<int>> &dp)
{
    if (i == lastRow)
        return TRIANGLE[lastRow][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = TRIANGLE[i][j] + memoSolve(TRIANGLE, i + 1, j, lastRow, dp);
    int diagonal = TRIANGLE[i][j] + memoSolve(TRIANGLE, i + 1, j + 1, lastRow, dp);

    return dp[i][j] = min(down, diagonal);
}

// tabulation Approach
int tabSolve(vector<vector<int>> &TRIANGLE, int n, vector<vector<int>> &dp)
{
    // base case
    for (int col = 0; col <= n; col++)
    {
        dp[n][col] = TRIANGLE[n][col];
    }

    // Going upwards
    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = TRIANGLE[row][col] + dp[row + 1][col];
            int diagonal = TRIANGLE[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// space optimized solution
int spOptSolve(vector<vector<int>> &TRIANGLE, int n)
{
    vector<int> front(n + 1, 0);
    vector<int> curr(n + 1, 0);

    // base case
    for (int col = 0; col <= n; col++)
    {
        front[col] = TRIANGLE[n][col];
    }


    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = TRIANGLE[row][col] + front[col];
            int diagonal = TRIANGLE[row][col] + front[col + 1];

            curr[col] = min(diagonal, down);
        }
        front = curr;
    }
    return front[0];
}

int main()
{
    int m;
    cin >> m;
    vector<vector<int>> TRIANGLE(m, vector<int>(m, 0));
    vector<vector<int>> memoDp(m, vector<int>(m, -1));
    vector<vector<int>> tabDp(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> TRIANGLE[i][j];
        }
    }

    int recAns = recSolve(TRIANGLE, 0, 0, m - 1);
    cout << "Recursive Solution : " << recAns << endl;

    int memoDpAns = memoSolve(TRIANGLE, 0, 0, m - 1, memoDp);
    cout << "Memo Solution : " << memoDpAns << endl;

    int tabDpAns = tabSolve(TRIANGLE, m - 1, tabDp);
    cout << "tab Solution : " << tabDpAns << endl;

    int spOptAns = spOptSolve(TRIANGLE, m - 1);
    cout << "space optimized Solution : " << spOptAns << endl;
}