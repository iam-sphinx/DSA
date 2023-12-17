/*
    Given a boolean 2D matrix grid of size n x m. You have to find the number of distinct islands where a group of connected 1s
    (horizontally or vertically) forms an islands. Two Islands are considered to be distinct if and only if one island is equal
    to another (not rotated or reflected.)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &vec, int rowBase, int colBase, int n, int m)
{
    vis[row][col] = true;
    vec.push_back({row - rowBase, col - colBase});

    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, -1, 0, 1};

    for (int a = 0; a < 4; a++)
    {
        int nRow = row + delx[a];
        int nCol = col + dely[a];

        if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && vis[nRow][nCol] == false && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, grid, vis, vec, rowBase, colBase, n, m);
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
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, grid, vis, vec, i, j, n, m);
                st.insert(vec);
            }
        }
    }

    cout << "Number of Distinct islands are : " << st.size();
}
