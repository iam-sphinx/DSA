/*
A directed graph V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer
in the range 0 to V - 1.

A node is a terminal node if ther are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal
node.

You have to return an array containing all the safe nodes of the graph. The answer should be stored in ascending order.

Approach :
    Any one part of cycle can not be safe node
    Any node leads to cycle can not be safe node
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> graph[], vector<bool> &path, vector<bool> &vis, vector<bool> &check, int node)
{
    vis[node] = true;
    path[node] = true;
    check[node] = false;

    for (auto adj : graph[node])
    {
        if (!vis[adj])
        {
            if (dfs(graph, path, vis, check, adj))
            {
                check[node] = false;
                return true;
            }
        }
        else if (path[node])
        {
            check[node] = false;
            return true;
        }
    }
    check[node] = true; // if you reached here it means you haven't found any cycle so good to go!
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
    vector<int> safeNodes;
    vector<bool> check(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(graph, path, vis, check, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
        {
            safeNodes.push_back(i);
        }
    }

    for(auto x : safeNodes)
    {
        cout<<x<<" ";
    }
}