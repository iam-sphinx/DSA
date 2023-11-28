/*
Given a grid of dimensions n x m where each cell in the grid have values 0, 1, 2 which has the following meaning:
0 - empty cell
1 - cells have fresh oranges
2 - cells have rotten oranges

we have to determine what is the minimum time required to rot all oranges. A rotten orange is at index [i, j] can rot other fresh orange at
indexes [i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1] (up, down, left, right) in unit time.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    //{{r, c}, t}
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Now pushing all rotten oranges at t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }
    // change
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Now Apply BFS technique
    int tm = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(tm, t);

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && graph[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && graph[i][j] == 1)
            {
                flag = -1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        cout << tm << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}