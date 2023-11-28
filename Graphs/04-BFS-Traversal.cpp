/* BFS of a GRAPH -> Traversal Technique */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // BFS
    vector<bool> visited(n + 1, false);

    // mark the first node (node 1) as visited
    visited[1] = true;

    // vector for BFS traversal
    vector<int> BFS;
    // creating a queue for bfs
    queue<int> que;
    que.push(1); // Start from node 1
    while (!que.empty())
    {
        int node = que.front();
        BFS.push_back(node);
        que.pop();

        for (auto it : graph[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                que.push(it);
            }
        }
    }

    // Now Printing BFS traversal of GRAPH
    for (auto it : BFS)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// Time Comp -> O(N) + O(2E)