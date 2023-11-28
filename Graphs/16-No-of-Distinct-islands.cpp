/*
Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or
vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected)

example :
    grid = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 0 ,0, 1, 1}}

    output : 1;
    explanation : island 1, 1 at the top left corner is same is island 1, 1 at the bottom right corner.

    TC - n x m x log(n x m) + (n x m x 4)
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &grid, vector<vector<bool>> &vis, int row, int col, int brow, int bcol, int delx[], int dely[], vector<pair<int, int>> &temp)
{
    vis[row][col] = true;
    temp.push_back({row - brow, col - bcol});
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delx[i];
        int ncol = col + dely[i];
        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && vis[nrow][ncol] == false)
        {
            DFS(grid, vis, nrow, ncol, brow, bcol, delx, dely, temp);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    set<vector<pair<int, int>>> st;
    vector<pair<int, int>> temp;
    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, -1, 0, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == false)
            {
                vector<pair<int, int>> temp;
                DFS(grid, vis, i, j, i, j, delx, dely, temp);
                st.insert(temp);
            }
        }
    }

    cout << st.size() << endl;
}