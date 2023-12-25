/*
Shortest path in Undirected Graph having unit distance

You are given an undirected graph having unit weight, find the shortest distance from src to all the points, if path is not possible then put -1.

Input : n = 9, m = 10
edges = [[0,1],[0,3],[3,4],[4,5],[1,2],[1,3],[5,6],[2,6],[6,7],[7,8],[6,8]]
src = 0;
output : 0 1 2 1 2 3 3 4 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> adj[], queue<int> &q, vector<int> &dist, vector<bool> &vis, int src)
{
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
            }
            if (!vis[it])
                q.push(it);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1, false);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, 1e9);
    queue<int> q;

    bfs(adj, q, dist, vis, 1);

    for (auto x : dist)
    {
        cout << x << " ";
    }
}