/*
    Maximum Connected Group

    You are given n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.
    You can change at most one cell in grid from 0 to 1.
    You need to find the largest group of connected 1's.
    Two cells are said to be connected if both are adjacent to each other and both have same value.

    Example 1
        Input :
            2
            1 1
            0 1
        Output :
            4
*/

#include <iostream>
#include <vector>
#include <set>
#include "DisjointSet.cpp"
using namespace std;

bool isValid(int row, int col, int n)
{
    return row >= 0 && row < n && col >= 0 && col < n;
}

int maxConnection(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];

                if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                {
                    int u = row * n + col;
                    int v = newr * n + newc;

                    ds.unionBySize(u, v);
                }
            }
        }
    }

    int max_val = INT_MIN;

    // now checking for zeros and try to get maxcount
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
            {
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                // using set to remove dublicacy
                set<int> parent;

                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = row + dr[ind];
                    int newc = row + dc[ind];

                    if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int node = newr * n + newc;
                        parent.insert(ds.findUlpParent(node));
                    }
                }
                int temp_val = 1;

                // now checking inside set
                for (auto it : parent)
                {
                    temp_val += ds.getSize(it);
                }
                max_val = max(temp_val, max_val);
            }
        }
    }

    // case to think when no zero is present
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
        max_val = max(max_val, ds.getSize(ds.findUlpParent(cellNo)));
    }

    return max_val;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << maxConnection(grid) << endl;
}