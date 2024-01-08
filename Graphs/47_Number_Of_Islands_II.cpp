/*
    Number of Islands - II (Outline Queries)

    You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix 
    elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
    The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] 
    from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.

    Note : An island means group of 1s such that they share a common side.

    Example 1:

        Input: n = 4
        m = 5
        k = 4
        A = {{1,1},{0,1},{3,3},{3,4}}

        Output: 1 1 2 2
    Explanation:
        0.  00000
            00000
            00000
            00000
        1.  00000
            01000
            00000
            00000
        2.  01000
            01000
            00000
            00000
        3.  01000
            01000
            00000
            00010
        4.  01000
            01000
            00000
            00011
*/

#include<iostream>
#include<vector>
#include<mem.h>
#include "DisjointSet.cpp"

bool isValid(int adjr, int adjc, int n, int m)
{
   return adjr >= 0 && adjr < n && adjc >=0 && adjc < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    DisjointSet ds(n * m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    vector<int> ans;

    for(auto it : operators)
    {
        int row = it[0];
        int col = it[1];

        if(vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int ind = 0; ind < 4; ind++)
        {
            int adjr = row + dr[ind];
            int adjc = col + dc[ind];

            if(isValid(adjr, adjc, n, m))
            {
                if(vis[adjr][adjc] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if(ds.findUlpParent(nodeNo) != ds.findUlpParent(adjNodeNo))
                    {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}


int main()
{
    int n, m,k;
    cin>>n>>m>>k;

    vector<vector<int>> operators;
    for(int i=0; i<k; i++)
    {
        int u,v;
        cin>>u>>v;
        operators.push_back({u,v});
    }

    vector<int> ans = numOfIslands(n,m,operators);

    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}