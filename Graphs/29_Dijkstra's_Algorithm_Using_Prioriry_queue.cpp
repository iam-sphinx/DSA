/*
    Dijkstra's Algorithm -> it is the algorithm used to find out shortest path from source to destination.

    use set or priority queue or queue

    Some relaxation of edges is done and at end we get our distance array.

    TC-> using pq -> E log V (where E is no of edges and V is no of nodes);
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int ds = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgewt = it.second;
            int adjNode = it.first;

            if (ds + edgewt < dist[adjNode])
            {
                dist[adjNode] = ds + edgewt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source;
    cin >> source;

    vector<int> dist = dijkstra(n, adj, source);
    for (auto x : dist)
    {
        cout << x << " ";
    }
    cout << endl;
}