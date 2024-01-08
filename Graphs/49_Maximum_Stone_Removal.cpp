/*

    There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.

    You need to remove some stones. 

    A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

    Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include "DisjointSet.cpp"

using namespace std;

int maxRemove(vector<vector<int>>&stones, int n)
{
    int maxRow = 0;
    int maxCol = 0;

    for(auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    // we are making ds of row + col where 0 -- n for row and n + 1 to end will be for col
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int,int> uniqueNodes;

    for(auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1]  + maxRow + 1;

        ds.unionBySize(nodeRow, nodeCol);
        uniqueNodes[nodeRow] = 1;
        uniqueNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it : uniqueNodes)
    {
        if(ds.findUlpParent(it.first) == it.first)
        {
            cnt++;
        }
    }
    return n - cnt;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> stones;

    for(int i=0; i<n; i++)
    {
        int row, col;
        cin>>row, col;
        stones.push_back({row, col});
    }

    cout<<maxRemove(stones, n)<<endl;

}