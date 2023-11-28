/* Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from to v to u or v to u.
Your task is to find out number of provinces

Note: A province is a group of directly or indirectly connected cities and no cities outside of the group.
 */

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], vector<bool> &vis, int node)
{
    vis[node] = true;
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            DFS(graph, vis, it);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    int prov = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            prov++;
            DFS(graph, vis, i);
        }
    }
    cout << prov << endl;
}