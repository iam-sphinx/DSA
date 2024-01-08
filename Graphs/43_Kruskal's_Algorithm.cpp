/*
    Kruskal's Algorithm is used to find out Minimum Spanning Tree.

    Algo-
        1> Sort all the edges according to wt. (wt, u , v)

    Que -
        Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of 
        the minimum spanning tree.

    Example -
        input :
            3 3
            0 1 5
            1 2 3
            0 2 1
        output :
            4
*/

#include "DisjointSet.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    DisjointSet ds(V);

    sort(edges.begin(), edges.end());
    int mstWt = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUlpParent(u) != ds.findUlpParent(v))
        {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj[n];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << spanningTree(n, adj) << endl;
}