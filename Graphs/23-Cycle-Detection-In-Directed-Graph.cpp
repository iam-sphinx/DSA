/* By using Kahn's Algorithm */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    vector<int> inDegree(n, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
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
        for (auto adj : graph[node])
        {
            inDegree[adj]--;
            if (inDegree[adj] == 0)
            {
                q.push(adj);
            }
        }
    }
    if (topo.size() == n)
    {
        cout << "NO it does not have any cycle" << endl;
    }
    else
    {
        cout << "Yes it is having a cycle" << endl;
    }
    return 0;
}