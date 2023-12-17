#include <iostream>
#include <vector>

using namespace std;

bool checkCycle(vector<bool> &vis, vector<bool> &pathVis, vector<int> adj[], int node)
{
    vis[node] = true;
    pathVis[node] = true;

    // traverse for adjacent node
    for (auto adjNode : adj[node])
    {
        // when node is not visited
        if (!vis[adjNode])
        {
            if (checkCycle(vis, pathVis, adj, adjNode) == true)
            {
                return true;
            }
        }
        // if visited then check if already on path or not
        else if (pathVis[adjNode])
        {
            return true;
        }
    }

    pathVis[node] = false;
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
    }

    vector<bool> vis(n + 1, false);
    vector<bool> pathVis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(vis, pathVis, adj, i))
            {
                cout << "YES cycle is present" << endl;
                return 0;
            }
        }
    }
    cout << "NO cycle is present" << endl;
    return 0;
}