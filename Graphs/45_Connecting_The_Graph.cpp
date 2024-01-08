/*
    You are given a graph with n vertices and m edges.
    You can remove one edge from anywhere and add that edge between any two vertices in one operation.
    Find the minimum number of operation that will be required to make the graph connected.

    Example 1:
        input:
            n = 4
            m = 3
            Edge = [ [0,1] , [0,2] , [1,2] ]
        Output: 1
        Explanation : Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
*/

#include<iostream>
#include<vector>
#include "DisjointSet.cpp"

using namespace std;

int solve(int n, vector<vector<int>> &edge)
{
    int extraEdge = 0;
    DisjointSet ds(n);
    for(auto it : edge)
    {
        int u = it[0];
        int v = it[1];

        if(ds.findUlpParent(u) == ds.findUlpParent(v))
        {
            extraEdge++;
        }
        else
        {
            ds.unionBySize(u,v);
        }
    }

    int cntC = 0;
    for(int i=0; i<n; i++)
    {
        if(ds.findUlpParent(i) == i)
        {
            cntC++;
        }
    }
    
    int ans = cntC - 1;
    if(extraEdge >= ans) return ans;
    return -1;

    
}

int main()
{
    int n, m;
    cin>>n >> m;

    vector<vector<int>> edge(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
    }

    cout<<solve(n, edge)<<endl;
}