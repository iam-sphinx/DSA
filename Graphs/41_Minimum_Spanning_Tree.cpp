/*
Minimum Spanning Tree - A tree in which we have N nodes and N-1 edges and all nodes are reachable from each other.
*/

/* PRIMS's ALGORITHM */

/*
    GREEDY IS INTUTION
    Try minimum each time and add to mst.
*/

/*
    Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the minimum spanning tree.
*/
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);

    // {wt, node}
    pq.push({0, 0});
    int sum = 0;

    // E
    while (!pq.empty())
    {
        // log E
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;

        // add it to mst
        vis[node] = 1;
        sum += wt;

        // log E
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
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