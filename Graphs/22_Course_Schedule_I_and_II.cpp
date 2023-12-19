/*
    There are a total of N tasks, labeled from 0 to N - 1. Some tasks may have prerequisites, for example to do task 0 you have to first
    complete task 1, which is expressed as a pair : [0,1].

    Given the toal number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

    intution : NO is cycle is formed.
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

    // part 2

    for (auto it : topo)
    {
        cout << it << " ";
    }
    cout << endl;

    // part 1
    topo.size() == n ? cout << "Possible" : cout << "Not Possible";
}