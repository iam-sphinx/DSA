/*
    Problem :- Given an undirected graph with V vertices. We say two vertices u & v belong to a single province if there is
    path from  u to v. your task is to find the number of provinces
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<bool> &vis, vector<int> adj[], int i)
{
    vis[i] = true;
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(vis, adj, i);
            count++;
        }
    }
    cout << "Number of provinces are : " << count << endl;
}