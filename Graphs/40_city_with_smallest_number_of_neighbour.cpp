/*
    City with the smallest number of neighbours at at distance
    Difficulty : Medium

    There are n cities numbered from 0 to n - 1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a biderectional and
    weighted edge between cities fromi to toi, and given the integer distancet. You need to find out a city with the smallest number
    of cities that are reachable through some path and whose distance is at mostt Distance, If there are multiple such cities, our
    answer will be the city with the greatest number.
    Note : That the distance of a path connecting cities i and j is equal to sum of the edges weights along the path.

    Example 1:
    Input N = 4, M = 4
    edges = [[0,1,3], [1,2,1], [1,3,4], [2,3,1]]
    distancet = 4
    output = 3
*/

#include <iostream>
#include <vector>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    // floyd warshall
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            if (dist[city][adjCity] <= distanceThreshold)
            {
                cnt++;
            }
        }

        if (cnt <= cntCity)
        {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> edges;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << findCity(n, m, edges, t) << endl;
}