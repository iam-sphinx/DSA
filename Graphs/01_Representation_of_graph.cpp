#include <iostream>
using namespace std;

int main()
{
    // here n = no of nodes & m = no of edges
    int n, m;
    cin >> n >> m;

    // now creating adjacancy matrix
    // space complexity N * N
    int adj[n + 1][n + 1] = {0};
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        //now creating undirected edge;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
} 