/*
    A directed graph of V vertices and E edges is given in the form of an adjacenecy list adj. Each node of the graph is labelled with a
    distinct integer in the range 0 to V - 1.

    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to
    a terminal node.

    You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

    intution : just reverse the direction of edges and find topological sort.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

    // now converting direction of edges.

    vector<int> rev[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            rev[it].push_back(i);
        }
    }

    vector<int> inDeg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto it : rev[i])
        {
            inDeg[it]++;
        }
    }

    // simple kahn Algorithm
    queue<int> q;

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

        for (auto it : rev[node])
        {
            inDeg[it]--;
            if (inDeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    sort(topo.begin(), topo.end());
    cout << "List of Safe Nodes are : " << endl;
    for (auto it : topo)
    {
        cout << it << " ";
    }
}
