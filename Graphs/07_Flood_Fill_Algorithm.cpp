/*
    Problem : An image is represented by a 2D array of integers, each integer representing the pixel value of the image.

    Given a coordinate (sr, sc) representing the starting pixel (row & columns) of the flood fill, and a pixel value newColor, "flood fill"
     the image.

    To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same
     directionally to those pixels (also with the same color as the starting pixel), and so on, Replace the color of all the aformentioned
      pixels with the newColor.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int sr, int sc, int newColor, int oldColor, vector<vector<int>> &newAdj, int n, int m)
{
    newAdj[sr][sc] = newColor;

    int delx[] = {-1, 0, 1, 0};
    int dely[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int newRow = sr + delx[i];
        int newCol = sc + dely[i];

        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && newAdj[newRow][newCol] == oldColor)
        {
            dfs(newRow, newCol, newColor, oldColor, newAdj, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    vector<vector<int>> newAdj = adj;

    int sr, sc;
    cout << "Enter source row and source col :" << endl;
    cin >> sr >> sc;

    int newColor;
    cout << "Enter new Color :" << endl;
    cin >> newColor;

    int oldColor = adj[sr][sc];

    dfs(sr, sc, newColor, oldColor, newAdj, n, m);

    cout << "Initial graph : " << endl;
    for (auto x : adj)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << "Flood Filled Graph : " << endl;
    for (auto x : newAdj)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}