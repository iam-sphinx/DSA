#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &adj, vector<vector<bool>> &vis, vector<vector<int>> &output, int n, int m)
{
    // here q is representing {{x,y} , minimum step}
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;

        int steps = q.front().second;

        q.pop();
        output[row][col] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == false)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(m, 0));
    vector<vector<int>> output(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    solve(adj, vis, output, n, m);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}