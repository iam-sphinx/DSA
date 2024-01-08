/*
    Strongly Connected Components - Kosaraju's Algorithm

    Only valid for Directed Graph.

    SCC -> Choose any pair and it should be reachable.

    (0) <- (2) -> (3) -> (4) -> (7)
     |    .               |  .   .
     .   /                .   \  |
     (1)                 (5) -> (6)

    strongly Connected Components are ->
    [0,1,2] , [3], [4,5,6] , [7]


    ALGORITHM -
     <o> Sort all the edges according to finishing time By DFS first time
     <o> Reverse the Graph.
     <o> Do a DFS


    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph of size V as inputs and returns an integer denoting the number of strongly connected components in the given graph.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void s1Dfs(int node, vector<int> gph[], int vis[], stack<int> &forder)
{
    vis[node] = 1;
    for (auto it : gph[node])
    {
        if (vis[it] == 0)
        {
            s1Dfs(it, gph, vis, forder);
        }
    }

    forder.push(node);
}

void s3Dfs(int node, vector<int> gphT[], int rVis[])
{
    rVis[node] = 1;
    for (auto it : gphT[node])
    {
        if (rVis[it] == 0)
        {
            s3Dfs(it, gphT, rVis);
        }
    }
}

int kosaraju(int n, vector<int> adj[])
{
    int vis[n] = {0};
    stack<int> finishing;

    // step 1 simple dfs to store finishing order
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            s1Dfs(i, adj, vis, finishing);
        }
    }

    // step 2 reverse a direction of graph
    vector<int> rev[n];
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            // i --> it so we will store it --> i
            rev[it].push_back(i);
        }
    }

    // step 3 do a dfs
    int revis[n] = {0};
    int scc = 0;
    while (!finishing.empty())
    {
        int node = finishing.top();
        finishing.pop();
        if (revis[node] == 0)
        {
            scc++;
            s3Dfs(node, rev, revis);
        }
    }
    return scc;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << kosaraju(n, adj) << endl;
    return 0;
}