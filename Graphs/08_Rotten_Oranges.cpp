/*
    Problem : Given a grid of dimension n * m where each cell in the grid can have values 0,1 or 2 whcih has the following meaning:
    0 : Empty cell
    1 : cells have fresh oranges
    2 : cells have rotten oranges

    We have to determine what is the minimum time required to rot all oranges. A rotten orange at index[i,j] can rot other fresh oranges at index[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1] (up, down, right, left) in unit time
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<vector<bool>> &vis, vector<vector<int>> &grid, int n, int m, queue<pair<pair<int, int>, int>> &q)
{

    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};
    int finalTime = 0;

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        finalTime = time;

        q.pop();
        for (int x = 0; x < 4; x++)
        {
            int newRow = row + delx[x];
            int newCol = col + dely[x];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && vis[newRow][newCol] == false && grid[newRow][newCol] == 1)
            {
                grid[newRow][newCol] = 2;
                vis[newRow][newCol] = true;
                q.push({{newRow, newCol}, time + 1});
            }
        }
    }
    return finalTime;
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

    queue<pair<pair<int, int>, int>> q;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2 && vis[i][j] == false)
            {
                q.push({{i, j}, 0});
            }
        }
    }

    count = bfs(vis, grid, n, m, q);
    cout << "Minimum time to rot all oranges are : " << count << endl;
}