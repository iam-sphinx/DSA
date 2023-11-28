#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> graph[], vector<int> &col, int node, int color)
{
    col[node] = color;
    for(auto adj : graph[node])
    {
        if(col[adj] == -1)
        {
            dfs(graph, col, adj, !color);
        }
        else if(col[adj] == color)
        {
            return false;
        }
    }
    return true;
}
    main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> col(n + 1, -1);

    bool flag = false;

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == -1)
        {
            if (dfs(graph, col, i, 0) == false)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag == true) 
    {
        cout<<"NO it is not Bipartite"<<endl;
    }
    else
    {
        cout<<"YES it is Bipartite"<<endl;
    }
    return 0;
}