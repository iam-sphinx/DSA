/*
    Path with minimum effort
    difficulty : medium

    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col]
    represents the height of cell (row, col). You are situated in the top-left cell, (0,0), and you hope to travel to the bottom-right cell,
    (rows-1, columns-1) (i.e, 0 indexed). you can move up, down,left or right and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(vector<vector<int>> &dist, vector<vector<int>> &heights, int drow, int dcol)
{
    // minimum distance at start is 0
    dist[0][0] = 0;

    // dijkstra
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, 0}});
    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.top();
        q.pop();

        int prow = it.second.first;
        int pcol = it.second.second;

        int dis = it.first;

        for (int i = 0; i < 4; i++)
        {
            int nrow = prow + delx[i];
            int ncol = pcol + dely[i];

            if (nrow >= 0 && ncol >= 0 && nrow <= drow && ncol <= dcol)
            {
                int diff = max(dis, abs(heights[prow][pcol] - heights[nrow][ncol]));
                if (diff < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = diff;
                    q.push({diff, {nrow, ncol}});
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    solve(dist, heights, n - 1, m - 1);
    for (auto x : dist)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}