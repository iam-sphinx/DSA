/*
    Number of ways to arrive at destination
    Difficulty : Medium
    You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some interactions. The inputs
    are generated such that you can reach any intersection from any other intersection and there is at most one road between any two intersections.

    You are given an integer n ans a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui
    and vi that takes timei minutes to travel. you want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the
    shortest ammount of time.

    Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it
    modulo 1e9 + 7.

    Example 1:
    input: n=7 , m = 10
    edges = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

    output: 5
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];
    int mod = (int)(1e9 + 7);
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            // this is the first time i am coming with this short distance
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> roads(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    cout << countPaths(n, roads) << endl;
}