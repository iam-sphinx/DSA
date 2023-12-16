/*
    Problem :
        Given a matrix mat of size N x M where every element is either 'O' of 'X'.
        Replace all 'O' with 'X' that are surrounded by 'X'. A 'O' (or set of 'O') is considered to be by surrounded by 'X' if there are
        'X' at locations just below, just above, just left, just right of it.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col, int n, int m)
{
    vis[row][col] = true;
    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};
    for (int x = 0; x < 4; x++)
    {
        int newrow = row + delx[x];
        int newcol = col + dely[x];
        if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < m && grid[newrow][newcol] == 'O' && vis[newrow][newcol] == false)
        {
            dfs(grid, vis, newrow, newcol, n, m);
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

    vector<vector<char>> out = grid;
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O' && vis[0][j] == false)
        {
            dfs(grid, vis, 0, j, n, m);
        }
        if (grid[n - 1][j] == 'O' && vis[n - 1][j] == false)
        {
            dfs(grid, vis, n - 1, j, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 'O' && vis[i][0] == false)
        {
            dfs(grid, vis, i, 0, n, m);
        }
        if (grid[i][m - 1] == 'O' && vis[i][m - 1] == false)
        {
            dfs(grid, vis, i, m - 1, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == 'O')
            {
                out[i][j] = 'X';
            }
        }
    }

    cout << endl;
    for (auto x : out)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}