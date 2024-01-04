/*
    Distance from the source (Bellman-Ford Algorithm)
    Difficulty :- Medium

    Given a weighted, directed and connected graph of V vertices and E edges. Find the shortest distance of all the vertex's from the 
    source vertex S.
    Note: If the Graph contains a negative cycle then return an array consisting of only -1.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int source)
{
    vector<int> dist(V, 1e8);
    dist[source] = 0;
    // for n-1 times
    for(int iter = 1; iter <= V-1; iter++)
    {

        // now relaxing all edges
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Nth relaxation to check negative cycle
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if(dist[u] != 1e8 && dist[u] + w < dist[v])
        {
            return {-1};
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i=0; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int source;
    cin>>source;

    vector<int> output = bellman_ford(n, edges, source);
    for(auto it : output)
    {
        cout<<it<<" ";
    } 
}

