#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    } 
    st.push(node);
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
    }

    vector<bool> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}