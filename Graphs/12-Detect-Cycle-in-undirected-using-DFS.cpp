#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> gph[], vector<bool> &vis, int parent, int node)
{
    vis[node] = true;
    for (auto it : gph[node])
    {
        if (!vis[it])
        {
            if (dfs(gph, vis, node, it))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> gph[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        gph[u].push_back(v);
        gph[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    if (dfs(gph, vis, -1, 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}