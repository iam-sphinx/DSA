#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<int> adj[], vector<bool> &vis, int start_node)
{
    // queue representing {node, parent}
    queue<pair<int, int>> q;

    q.push({start_node, start_node});
    vis[start_node] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            // it is the case of loop where a node is already visited but it was not it's parent
            if (vis[it] && it != parent)
            {
                return true;
            }
            if (!vis[it])
            {
                vis[it] = true;
                // here next node will be it & parent will be current node
                q.push({it, node});
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
    vector<bool> vis(n + 1, false);

    // case to handle connected components
    bool res = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            res = bfs(adj, vis, i);
        }

        if (res == true)
        {
            break;
        }
    }

    res ? cout << "Yes cycle is present" : cout << "No cycle is not present";
}