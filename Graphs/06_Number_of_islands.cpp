/*
    Problem : Given a gridof size n * m (n is the number of rows and m is number of columns in the grid) consisting of '0's (water) and '1's (land).
    Find the number of islands.
    Note : An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or digonally i.e., in all 8
     directions
*/
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &adj, int n, int m)
{
    vis[row][col] = 1;
    int delx[3] = {-1, 0, 1};
    int dely[3] = {-1, 0, 1};

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            int newRow = row + delx[x];
            int newCol = col + dely[y];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && vis[newRow][newCol] == 0 && adj[newRow][newCol] == 1)
            {
                dfs(newRow, newCol, vis, adj, n, m);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && adj[i][j] == 1)
            {
                count++;
                dfs(i, j, vis, adj, n, m);
            }
        }
    }
    cout << "Number of Islands are : " << count << endl;
}
