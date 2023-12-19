/*
    Find wether a directed graph has cycle or not

    intution : Just try to find out whether possible or not if not then sure a cycle is present.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    }

    queue<int> q;
    vector<int> inDeg(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            inDeg[it]++;
        }
    }

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

        for (auto it : adj[node])
        {
            inDeg[it]--;
            if (inDeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    topo.size() == n ? cout << "NO cycle is present." : cout << "Yes cycle is present.";
}
