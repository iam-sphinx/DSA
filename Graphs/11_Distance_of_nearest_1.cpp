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
                adj[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;

        q.pop();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};

        for (int a = 0; a < 4; a++)
        {
            int X = x + delx[a];
            int Y = y + dely[a];

            if (X >= 0 && X < n && Y >= 0 && Y < m && adj[X][Y] == 0 && vis[X][Y] == false)
            {
                output[X][Y] = t + 1;
                vis[X][Y] = true;
                q.push({{X, Y}, t + 1});
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