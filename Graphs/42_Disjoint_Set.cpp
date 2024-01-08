#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimateParentOf_U = findUltimateParent(u);
        int ultimateParentOf_V = findUltimateParent(v);

        if (ultimateParentOf_U == ultimateParentOf_V)
        {
            return;
        }

        if (rank[ultimateParentOf_U] < rank[ultimateParentOf_V])
        {
            parent[ultimateParentOf_U] = ultimateParentOf_V;
        }
        else if (rank[ultimateParentOf_V] < rank[ultimateParentOf_U])
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
        }
        else
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
            rank[ultimateParentOf_U]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimateParentOf_U = findUltimateParent(u);
        int ultimateParentOf_V = findUltimateParent(v);

        if (ultimateParentOf_U == ultimateParentOf_V)
            return;

        if (size[ultimateParentOf_U] < size[ultimateParentOf_V])
        {
            parent[ultimateParentOf_U] = ultimateParentOf_V;
            size[ultimateParentOf_V] += size[ultimateParentOf_U];
        }
        else
        {
            parent[ultimateParentOf_V] = ultimateParentOf_U;
            size[ultimateParentOf_U] += size[ultimateParentOf_V];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 are same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "No\n";
    }
    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}