/*
You are given an N x M binary matrix grid, where 0 represent a sea cell and 1 represent a land cell.
A move consists of walking from one land to cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

example :
input n = 4, m = 4
grid = {{0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}}
output = 3
explanation :
        {{0, 0, 0, 0},
        {1, 0, (1), 0},
        {0, (1), (1), 0},
        {0, 0, 0, 0}}

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int row, int col, int delx[], int dely[])
{
    vis[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delx[i];
        int ncol = col + dely[i];
        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && vis[nrow][ncol] == false)
        {
            dfs(grid, vis, nrow, ncol, delx, dely);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, -1, 0, 1};

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 && vis[i][0] == false)
        {
            dfs(grid, vis, i, 0, delx, dely);
        }
        if (grid[i][m - 1] == 1 && vis[i][m - 1] == false)
        {
            dfs(grid, vis, i, m - 1, delx, dely);
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1 && vis[0][j] == false)
        {
            dfs(grid, vis, 0, j, delx, dely);
        }
        if (grid[n - 1][j] == 1 && vis[n - 1][j] == false)
        {
            dfs(grid, vis, n - 1, j, delx, dely);
        }
    }

    cout << endl;
    for (auto x : vis)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == false)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}