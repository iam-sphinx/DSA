/*
    Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v
     to u. Your task is to find out the number of provinces.

    Note : A province is a group of directly or indirectly connected cities and no other cities outside of the group.

    Example 1:
    [
        [1,0,1],
        [0,1,0],
        [1,0,1]
    ]

    output = 2;
*/

#include "DisjointSet.cpp"
#include <iostream>
#include <vector>
using namespace std;

int numProvinces(vector<vector<int>> &adj, int V)
{
    int cnt = 0;
    DisjointSet ds(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
            {
                ds.unionByRank(i, j);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (ds.findUlpParent(i) == i)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    cout << numProvinces(adj, n);
}
