#include <vector>
#include <iostream>
using namespace std;


class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);

        // initialize rank with 0
        rank.resize(n + 1, 0);

        // initialze size with 1
        size.resize(n + 1, 1);

        // initalize parent themselves at begining
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUlpParent(int node)
    {
        if (parent[node] == node)
            return node;

        // also doing path compression
        return parent[node] = findUlpParent(parent[node]);
    }

    // union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);

        // if same ultimate parent i.e already joined no need to do any thing
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // same rank so any one will be considered but this time rank will be updated.
            parent[ulp_v] = ulp_u;

            // rank will be increased of node in which another is attached.
            rank[ulp_u]++;
        }
    }

    // union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);

        // if both ultimate parent same already connectd
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
