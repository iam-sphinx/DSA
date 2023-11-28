/* Khan's algorithm for topological Ordering
    Approach :
        * Insert all nodes with indegree 0
        * Take them out of the queue and decrease their indegree by 1
*/

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
    for(auto x : topo)
    {
        cout<<x<<" ";
    }
    return 0;
}