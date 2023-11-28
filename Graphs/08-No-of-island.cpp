#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &graph, vector<vector<int>> &isVisited, int row, int col)
{
    isVisited[row][col] = 1;
    queue<pair<int, int>> que;
    que.push({row, col});

    while (!que.empty())
    {
        int row = que.front().first;
        int col = que.front().second;
        isVisited[row][col] = 1;
        que.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int r = row + i;
                int c = col + i;
                if (r >= 0 && c >= 0 && r < graph.size() && c < graph[0].size() && graph[r][c] == 1 && isVisited[r][c] == 0)
                {
                    isVisited[r][c] = 1;
                    que.push({r, c});
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    vector<vector<int>> isVisited(n + 1, vector<int>(n + 1, 0));
    int land = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (isVisited[i][j] == 0 && graph[i][j] == 1)
            {
                land++;
                BFS(isVisited, graph, i, j);
            }
        }
    }
    cout << land << endl;
    return 0;
}

// Space Complexity : O (N * N) + O(N * N)
// Time Complexity : O(N * N)
