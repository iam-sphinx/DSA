/*
    you are given weighted undirected graph having n vertices and m edges describing there are edges between a to b with some weight, find the
    shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only 1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void dijkstra(int source, vector<int> &min_dist, vector<int> &parent, vector<pair<int, int>> adj[])
{
    min_dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgewt = it.second;

            if (dis + edgewt < min_dist[adjNode])
            {
                min_dist[adjNode] = dis + edgewt;
                parent[adjNode] = node;
                pq.push({min_dist[adjNode], adjNode});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> min_dist(n, 1e9);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    dijkstra(source, min_dist, parent, adj);

    vector<int> path;
    int it = n;
    while (parent[it] != it)
    {
        path.push_back(it);
        it = parent[it];
    }

    for (auto x : path)
    {
        cout << x << " ";
    }
}