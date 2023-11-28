/*
Bipartite Graph - You can color the graph with two color such that no adjacent nodes have the same color

Example -
                      (Red) --- (Blue)
                     /                \
                    /                  \
    (Red) --- (Blue)                    (Red) --- (Blue) --- (Red)
                    \                  /
                     \                /
                      (Red) --- (Blue)

                      This is an example of Bipartite Graph

                      (Red)
                     /     \
                    /       \
    (Red) --- (Blue)       (Red) --- (Blue) --- (Red)
                  |          |
                  |          |
                 ( ? ) --- (Blue)
                    This is not a Bipartite Graph

    * A linear graph (no cycle) are always Bipartite Graph
    * Any Graph with even cycle length are always Bipartite Graph
    * All Graph with odd cycle are not Bipartite Graph
*/

#include <bits/stdc++.h>
using namespace std;

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
        graph[v].push_back(u);
    }

    bool flag = false;

    vector<int> col(n + 1, -1);
    queue<int> q;
    q.push(1);
    col[1] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adj : graph[node])
        {
            // if adj node is yet to color
            if (col[adj] == -1)
            {
                col[adj] = !col[node];
                q.push(adj);
            }
            // is the adj node having same color
            // someone in past filled the color
            else if (col[adj] == col[node])
            {
                flag = true;
                break;
            }
        }
    }

    flag == true ? cout << "NO it is not Bipartite \n" : cout << "YES it is! \n";
}