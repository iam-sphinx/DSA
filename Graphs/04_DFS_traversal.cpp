#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<bool> &vis, vector<int> adj[], vector<int> &dfs_list)
{
    vis[i] = true;
    dfs_list.push_back(i);

    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, dfs_list);
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
    vector<int> dfs_list;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, dfs_list);
        }
    }
    for (auto x : dfs_list)
    {
        cout << x << " ";
    }
}