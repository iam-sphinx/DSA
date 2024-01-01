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
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto it = *st.begin();
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.second;
            int edgewt = it.first;

            if (dis + edgewt < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgewt;
                st.insert({dist[adjNode], adjNode});
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