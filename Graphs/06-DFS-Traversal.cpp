/* DFS Traversal for GRAPH */

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> &ds, vector<int> graph[], vector<bool> &isVisited, int node)
{

    isVisited[node] = true;
    ds.push_back(node);
    for (auto it : graph[node])
    {
        if (!isVisited[it])
        {
            DFS(ds, graph, isVisited, it);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // DFS
    vector<int> ds;

    vector<bool> isVisited(n + 1, false);
    // DFS call
    DFS(ds, graph, isVisited, 1);

    // Printing DFS
    for (auto it : ds)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// SC -> O(N) + O(N) + O(N) + O(2*E)