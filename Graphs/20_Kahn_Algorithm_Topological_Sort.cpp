#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> inDeg(n + 1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            inDeg[it]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // node is in topo sort
        //  remove it from the indegree

        for (auto it : adj[node])
        {
            inDeg[it]--;
            if (inDeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    for (auto x : topo)
    {
        cout << x << " ";
    }
}