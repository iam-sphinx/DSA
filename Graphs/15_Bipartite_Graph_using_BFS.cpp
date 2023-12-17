/*
    A Bipartite Graph is a graph where we can fill all the nodes with 2 colors but condition is that none of adjacent nodes have same color.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkBipartite(vector<int> adj[], vector<int> &color, int idx)
{
    queue<pair<int, int>> q;
    q.push({idx, 0});
    color[idx] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int col = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (color[adjNode] == -1)
            {
                color[adjNode] = !col;
                q.push({adjNode, !col});
            }
            else if (color[adjNode] == col)
            {
                return false;
            }
        }
    }
    return true;
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

    // initial condition -1 represent no color yet filled
    vector<int> color(n + 1, -1);
    bool result = false;

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (checkBipartite(adj, color, i))
            {
                result = true;
                break;
            }
        }
    }

    result ? cout << "Yes Bipartite" : cout << "Not Bipartite";
}
