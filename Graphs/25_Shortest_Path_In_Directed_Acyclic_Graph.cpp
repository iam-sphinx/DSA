/*
    Given a Directed acyclic Graph. Find the shortest path from src(0). to all the vertex.

    Example :
    Input :
    n = 6, m = 7
    adj = [ [0, 1, 2], [0, 4, 1], [4, 5, 4], [4, 2, 2], [1, 2, 3], [2, 3, 6], [5, 3, 1]]
    src = 0
    output:
    0 2 3 6 1 5

    You don't need to print or input anything. Complete the function shortest path() which takes an directed acyclic graph, an integer
    n and an integer src as the input parameters and returns an integer, denoting the vector of distance from src to all nodes.

    Algo -
    1> Do a TopoSort
    2> Take all the nodes one by one and relax the edges.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSort(vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &topo, int i)
{
    vis[i] = true;

    for (auto it : adj[i])
    {
        int node = it.first;
        if (!vis[node])
        {
            topoSort(adj, vis, topo, node);
        }
    }

    topo.push(i);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    vector<bool> vis(n, false);
    vector<int> dis(n , 1e9);
    stack<int> topo;

    // step1 TopoSort
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort(adj, vis, topo, i);
        }
    }

    int x = topo.top();
    dis[x] = 0;
    // now performing step 2 i.e removing edges one by one and doing relaxation
    while(!topo.empty())
    {
        int node = topo.top();
        topo.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int adjNodeWt = it.second;
            if(dis[node] + adjNodeWt < dis[adjNode])
            {
                dis[adjNode] = dis[node] + adjNodeWt;
            }
        }
    }

    for(auto it :dis)
    {
        cout<<it<<" ";
    }
}