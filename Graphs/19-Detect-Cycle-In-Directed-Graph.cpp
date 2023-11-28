/*
How to detect a cycle in Directed Graph
    (1) --> (2) --> (3) --> (4)
            ^        |       |
           /         V       V
         (8)        (7) --> (5) --> (6)
          | ^
          V  \
         (9)->(10)
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> graph[], vector<bool> &vis, vector<bool> &path, int node)
{
    vis[node] = true;
    path[node] = true;

    for (auto adj : graph[node])
    {
        if (!vis[adj])
        {
            if (dfs(graph, vis, path, adj))
            {
                return true;
            }
        }
        else if (path[adj])
        {
            return true;
        }
    }
    path[node] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<bool> vis(n + 1, false);
    vector<bool> path(n + 1, false);

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(graph, vis, path, i) == true)
            {
                flag = true;
                break;
            }
        }
    }
    flag == true ? cout << "Yes Cycle is Present" : cout << "No Cycle is not present";
    return 0;
}