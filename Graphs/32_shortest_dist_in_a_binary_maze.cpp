/*
    Shortest Distance in a Binary Maze.
    Difficulty : Medium

    Given a n * m matrix grid where each element can neither 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.
    if the path is not possible between source cell and destination cell, then return -1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(vector<vector<int>> &dist, vector<vector<int>> &grid, int srow, int scol, int drow, int dcol, int n, int m)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {srow, scol}});

    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int prow = it.second.first;
        int pcol = it.second.second;

        int wt = it.first;
        for (int i = 0; i < 4; i++)
        {
            int nrow = prow + delx[i];
            int ncol = pcol + dely[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
            {
                if (wt + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = wt + 1;
                    q.push({wt + 1, {nrow, ncol}});
                }
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

    int srow, scol, drow, dcol;
    cin >> srow >> scol >> drow >> dcol;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[srow][scol] = 0;
    solve(dist, grid, srow, scol, drow, dcol, n, m);

    // cout<<dist[drow][dcol];
    for (auto x : dist)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}