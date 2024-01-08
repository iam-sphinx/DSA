/*
    tin[] -> DFS time inserts on
    low[] -> min lowest time insertion of all adjacent nodes apart from parent.

    There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i]
    = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

    A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

    Return all critical connections in the network in any order.

    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
        Output: [[1,3]]
        Explanation: [[3,1]] is also accepted.
        Example 2:

        Input: n = 2, connections = [[0,1]]
        Output: [[0,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges, int &timer)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        // case to not consider because we are taking consideration of anoter path no sense of keep same path back
        if (it == parent)
            continue;

        if (vis[it] == 0)
        {
            dfs(it, node, vis, adj, tin, low, bridges, timer);
            low[node] = min(low[node], low[it]);

            // node -- it can be bridge
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections, int timer)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];

    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges, timer);
    return bridges;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections;

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        connections.push_back({u, v});
    }

    vector<vector<int>> ans = criticalConnections(n, connections, 0);

    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}