/*  Flood Fill Algorithm
    An image is represented by a 2D array of integers, each integer representing the pixel value of the image

    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the
    image.

    To perfirm a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel to the same color as
    the starting pixel, plus any pixels connected 4 - directionally to those pixels (also with the same color as the starting pixel), and so on.
    Replace the color of all of the aforementioned pixels with the newColor.

*/

// check GFG
#include <bits/stdc++.h>
using namespace std;

void DFS(int initalColor, int newColor, int x, int y, vector<vector<int>> &graph, vector<vector<int>> &temp, int delRow[], int delCol[])
{
    temp[x][y] = newColor;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         int nrow = x + delRow[i];
    //         int ncol = y + delCol[j];
    //         if (nrow >= 0 && ncol >= 0 &&)
    //     }
    // }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> temp = graph;

    int x, y;
    cin >> x >> y;
    int newColor;
    cin >> newColor;

    int initialColor = graph[x][y];
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    DFS(initialColor, newColor, x, y, graph, temp, delRow, delCol);
    for (auto it : temp)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
