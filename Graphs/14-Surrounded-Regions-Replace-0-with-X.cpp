/*
Given a  matrix of size N x M where every element is either 'O' or 'X'.
Replace all 'O' with 'X' that are surrounded by 'X' if there are 'X' at location just below, just above, just left and just right of it.

Example :
input n = 5, m = 4
mat = { {'X' , 'X' , 'X' , 'X' },
        {'X' , 'O' , 'X' , 'X' },
        {'X' , 'O' , 'O' , 'X' },
        {'X' , 'O' , 'X' , 'X' },
        {'X' , 'X' , 'O' , 'O' }, }

out = { {'X' , 'X' , 'X' , 'X' },
        {'X' , 'X' , 'X' , 'X' },
        {'X' , 'X' , 'X' , 'X' },
        {'X' , 'X' , 'X' , 'X' },
        {'X' , 'X' , 'O' , 'O' }, }
*/
/* Solution :
    Traverse to all zeroes from boundary and mark them vis
    and in output make all X expect those are visited;
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col, int delx[], int dely[])
{
    vis[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delx[i];
        int ncol = col + dely[i];
        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 'O' && vis[nrow][ncol] == false)
        {
            dfs(grid, vis, nrow, ncol, delx, dely);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
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
        if (grid[i][0] == 'O' && vis[i][0] == false)
        {
            dfs(grid, vis, i, 0, delx, dely);
        }
        if (grid[i][m - 1] == 'O' && vis[i][m - 1] == false)
        {
            dfs(grid, vis, i, m - 1, delx, dely);
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O' && vis[0][j] == false)
        {
            dfs(grid, vis, 0, j, delx, dely);
        }
        if (grid[n - 1][j] == 'O' && vis[n - 1][j] == false)
        {
            dfs(grid, vis, n - 1, j, delx, dely);
        }
    }

    vector<vector<char>> output = grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false)
            {
                output[i][j] = 'X';
            }
        }
    }
    cout << endl;
    for (auto x : output)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}