/*
    A directed graph of V vertices and E edges is given in the form of an adjacenecy list adj. Each node of the graph is labelled with a
    distinct integer in the range 0 to V - 1.

    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to
    a terminal node.

    You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

#include <iostream>
#include <vector>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, vector<bool> &check)
{
    vis[node] = true;
    pathVis[node] = true;
    check[node] = false;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, check) == true)
            {
                
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }

    check[node] = true;
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
    vector<bool> check(n + 1, false);

    vector<int> safeNodes;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            safeNodes.push_back(i);
    }

    for (auto x : safeNodes)
    {
        cout << x << " ";
    }
}