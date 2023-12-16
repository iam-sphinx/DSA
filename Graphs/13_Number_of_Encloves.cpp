/*
    You are given an n x m binary matrix grid. where 0 represent a sea cell and 1 represent a land cell.
    A move consist of walking from one land cell to another adjacent (4 directional) land cell or walking off the boundary of the grid.
    Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<bool>> &vis, vector<vector<int>> &grid, int row, int col, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = true;

    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int nrow = q.front().first;
        int ncol = q.front().second;
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            int trow = nrow + delx[a];
            int tcol = ncol + dely[a];

            if (trow >= 0 && tcol >= 0 && trow < n && tcol < m && vis[trow][tcol] == false && grid[trow][tcol] == 1)
            {
                vis[trow][tcol] = true;
                q.push({trow, tcol});
            }
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

    for (int j = 0; j < m; j++)
    {
        if (vis[0][j] == false && grid[0][j] == 1)
        {
            bfs(vis, grid, 0, j, n, m);
        }
        if (vis[n - 1][j] == false && grid[n - 1][j] == 1)
        {
            bfs(vis, grid, n - 1, j, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i][0] == false && grid[i][0] == 1)
        {
            bfs(vis, grid, i, 0, n, m);
        }
        if (vis[i][m - 1] == false && grid[i][m - 1] == 1)
        {
            bfs(vis, grid, i, m - 1, n, m);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    cout << "Total no of 1s where we can not went to boundary are : " << count << endl;
}