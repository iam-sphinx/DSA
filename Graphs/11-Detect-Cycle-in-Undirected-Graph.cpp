#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], vector<bool> &vis)
{
    vis[src] = true;
    queue<pair<int, int>> q;
    q.push({1, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = true;
                q.push({adjacentNode, node});
            }
            else if (parent != adjacentNode)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<bool> vis(n, false);

    bool flag = false;

    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
            {
                flag = true;
            }
        }
    }
    if (flag == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

// TC -> O(N + 2E)