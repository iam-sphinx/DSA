#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int x, vector<bool> &vis, vector<int> adj[], vector<int> &bfs)
{
    queue<int> q;
    q.push(x);
    vis[x] = true;

    while (!q.empty())
    {
        int node = q.front();
        bfs.push_back(node);
        vis[node] = true;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    vector<int> bfs;

    for (int i=1; i<=n; i++)
    {
        if (vis[i] == false)
        {
            BFS(i, vis, adj, bfs);
        }
    }

    for (auto x : bfs)
    {
        cout << x << " ";
    }
    return 0;
}