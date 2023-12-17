#include <iostream>
#include <vector>
using namespace std;

bool checkBipartite(vector<int> adj[], vector<int> &color, int idx, int col)
{
    color[idx] = col;
    for (auto adjNode : adj[idx])
    {
        if (color[adjNode] == -1)
        {
            if (checkBipartite(adj, color, adjNode, !col) == false)
            {
                return false;
            }
        }
        else if (color[adjNode] == col)
        {
            return false;
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

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (checkBipartite(adj, color, i, 0))
            {
                cout << "Yes it is Bipartite";
                return 0;
            }
        }
    }
    cout << "No it is not Bipartite";
    return 0;
}