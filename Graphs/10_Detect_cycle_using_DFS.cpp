#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(vector<int> adj[], vector<bool> &vis, int node, int parent)
{
    vis[node] = true;

    for (auto adjacentNode : adj[node])
    {
        // it is the case of not visited
        if (!vis[adjacentNode])
        {
            // we will terminate if our function return true
            if (detectCycle(adj, vis, adjacentNode, node))
            {
                return true;
            }
        }
        // return true when loop fount i.e visited && parent != adjacentNode
        else if (parent != adjacentNode)
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

    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    bool res = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            res = detectCycle(adj, vis, i, -1);
        }
        if (res == true)
        {
            break;
        }
    }
    res ? cout << "YES Cycle is present" : cout << "NO cycle is present";
}