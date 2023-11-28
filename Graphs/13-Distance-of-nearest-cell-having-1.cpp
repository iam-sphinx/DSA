#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                dist[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        dist[row][col] = dis;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delx[i];
            int ncol = col + dely[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == false)
            {
                vis[row][col] = true;
                q.push({{nrow, ncol}, dis + 1});
            }
        }
    }
    for (auto x : dist)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}