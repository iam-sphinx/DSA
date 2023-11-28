/* Ninja has a 'GRID' of size 'n' x 'm'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to
collect as many chocolates as possible with the help of his friends.

initially, Alice is in the top-left position i.e. (0 , 0) and Bob is in the top-right place i.e. (0,'m'-1) in the grid. Each of them can move
from their current cell to the cells just below them. When anyonw passes from any cell, he will pick all chocolates in it. and then the number
of chocoloates in that cell will become zero. if both stay in the same cell, only one of them will pickup the chocolates in it.

if Alice or Bob is at (i,j) then they can move (i + 1 , j), (i + 1 , j - 1) or (i + 1 , j + 1). They will always stay inside the 'GRID'.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.
*/

// NOTE: This is a 3D dp problem.

/*
Rules to solve this problem

(1) express everything in terms of (i1, j1) & (i2, j2) for Alice and Bob resp.
(2) explore all the path down, down-left, down-right
(3) Maximum sum return
*/

/* psudo code
f(i, j1, j2)
{
    //out of bound case
    if(j1<0 || j1>=m || j2<0 || j2>=m)
    {
        return -1e8
    }

    //base case
    if(i == n-1)
    {
        if(j1 == j2)
        return a[i][j1];

        else
        return a[i][j1] + a[i][j2];
    }

    //explore all path
    int maxi = -1e8;
    for(di1 -> -1 -> +1)
    {
        for(dj2 ->-1 -> +1)
        {
            if(j1 == j2)
            {
                res = a[i][j1] + f(i+1, j1+dj1, j2+dj2);
                maxi = max(maxi, res);
            }
            else
            {
                res = a[i][j1] + a[i][j2] + = f(i+1, j1+dj1, j2+dj2);
                maxi = max(maxi, res);
            }
        }
    }
    return maxi;
}

TC -> O(3^n * 3^n) ~ exponential
SC -> O(N)

MEMOIZATION
(i)(j1)(j2)
[N] X [M] X [M]
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int recSolve(vector<vector<int>> &GRID, int row, int Alice_col, int Bob_col)
{
    int last_row = GRID.size();
    int last_col = GRID[0].size();
    // dead end case
    if (Alice_col < 0 || Alice_col >= last_col || Bob_col < 0 || Bob_col >= last_col)
    {
        return -1e8;
    }

    // base case
    if (row == last_row - 1)
    {
        if (Alice_col == Bob_col)
            return GRID[row][Alice_col];
        else
            return GRID[row][Alice_col] + GRID[row][Bob_col];
    }

    // explore all case
    int out = -1e8;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (Alice_col == Bob_col)
            {
                int ans = GRID[row][Alice_col] + recSolve(GRID, row + 1, Alice_col + i, Bob_col + j);
                out = max(out, ans);
            }
            else
            {
                int ans = GRID[row][Alice_col] + GRID[row][Bob_col] + recSolve(GRID, row + 1, Alice_col + i, Bob_col + j);
                out = max(out, ans);
            }
        }
    }
    return out;
}

// Memoization Solution

int memoSolve(vector<vector<int>> &GRID, int row, int Alice_col, int Bob_col, vector<vector<vector<int>>> &dp)
{
    int last_row = GRID.size();
    int last_col = GRID[0].size();
    // dead end case
    if (Alice_col < 0 || Alice_col >= last_col || Bob_col < 0 || Bob_col >= last_col)
    {
        return -1e8;
    }

    // base case
    if (row == last_row - 1)
    {
        if (Alice_col == Bob_col)
            return GRID[row][Alice_col];
        else
            return GRID[row][Alice_col] + GRID[row][Bob_col];
    }

    if (dp[row][Alice_col][Bob_col] != -1)
        return dp[row][Alice_col][Bob_col];

    // explore all case
    int out = -1e8;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (Alice_col == Bob_col)
            {
                int ans = GRID[row][Alice_col] + memoSolve(GRID, row + 1, Alice_col + i, Bob_col + j, dp);
                out = max(out, ans);
            }
            else
            {
                int ans = GRID[row][Alice_col] + GRID[row][Bob_col] + memoSolve(GRID, row + 1, Alice_col + i, Bob_col + j, dp);
                out = max(out, ans);
            }
        }
    }
    return dp[row][Alice_col][Bob_col] = out;
}

// Tabulation Solution
int tabSolve(vector<vector<int>> &GRID, vector<vector<vector<int>>> &dp)
{
    int row_size = GRID.size();
    int col_size = GRID[0].size();

    // base case
    for (int j1 = 0; j1 < col_size; j1++)
    {
        for (int j2 = 0; j2 < col_size; j2++)
        {
            if (j1 == j2)
            {
                dp[row_size - 1][j1][j2] = GRID[row_size - 1][j1];
            }
            else
            {
                dp[row_size - 1][j1][j2] = GRID[row_size - 1][j1] + GRID[row_size - 1][j2];
            }
        }
    }

    // explore all paths
    for (int i = row_size - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < col_size; j1++)
        {
            for (int j2 = 0; j2 < col_size; j2++)
            {
                int out = -1e8;
                for (int dj1 = -1; dj1 < 2; dj1++)
                {
                    for (int dj2 = -1; dj2 < 2; dj2++)
                    {
                        if (j1 == j2)
                        {
                            int ans;
                            if (j1 + dj1 >= 0 && j1 + dj1 < col_size && j2 + dj2 >= 0 && j2 + dj2 < col_size)
                                ans = GRID[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                ans = -1e8;
                            out = max(out, ans);
                        }
                        else
                        {
                            int ans;
                            if (j1 + dj1 >= 0 && j1 + dj1 < col_size && j2 + dj2 >= 0 && j2 + dj2 < col_size)
                                ans = GRID[i][j1] + GRID[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                ans = -1e8;
                            out = max(out, ans);
                        }
                    }
                }
                dp[i][j1][j2] = out;
            }
        }
    }
    return dp[0][0][col_size - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> GRID(n, vector<int>(m, 0));
    // dp of [n][m][m]
    vector<vector<vector<int>>> MemoDp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    vector<vector<vector<int>>> TabDp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (auto i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> GRID[i][j];
        }
    }

    int recAns = recSolve(GRID, 0, 0, m - 1);
    cout << "Recursive solution : " << recAns << endl;

    int memoAns = memoSolve(GRID, 0, 0, m - 1, MemoDp);
    cout << "Memoization Solution : " << memoAns << endl;

    int tabAns = tabSolve(GRID, TabDp);
    cout << "Tabulation Solution : " << tabAns << endl;
}