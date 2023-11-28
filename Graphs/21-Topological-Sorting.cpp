/* Topological Sorting ( only for DAG)

    Linear ordaring of vertices such that if there is an edge between u & v, u always appears before v in that ordering

    example :
        (5)          (4)
         | \       / |
         |  \     /  |
         |    V  V   |
         |     (0)   |
         V           V
        (2)-->(3)-->(1)
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], vector<bool> &vis, int node, stack<int> &st)
{
    vis[node] = true;

    for (auto adj : graph[node])
    {
        if (!vis[adj])
        {
            dfs(graph, vis, adj, st);
        }
    }
    st.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> path(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(graph, vis, i, st);
        }
    }
    vector<int> output;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        output.push_back(node);
    }
    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}