/*
    Articulation Point -> Nodes on whose removal the graph breaks into multiple components.

    tin[] - Store the time of insertion during dfs
    low[] - min of all adjacent nodes apaer from parent and visited nodes.

    remember :- low will be updated when if it is not pareant and not visited. if it is visited takes the time of consideration.
    if(low[it] >= tin[node] && parent != -1)



    Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int>&vis, int tin[], int low[],vector<int>&mark, vector<int>adj[], int &timer)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;

    for(auto it : adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            dfs(it, node, vis, tin, low, mark, adj, timer);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if(child > 1 && parent == -1)
    {
        mark[node] = 1;
    }

}
vector<int> articulationPoints(int n, vector<int> adj[])
{
    int timer = 1;
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];

    vector<int> mark(n, 0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i, -1, vis, tin, low, mark, adj, timer);
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        if(mark[i] == 1)
        {
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) return {-1};
    return ans;

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
        adj[v].push_back(u);
    }

    for (auto it : articulationPoints(n, adj))
    {
        cout << it << " ";
    }
}
