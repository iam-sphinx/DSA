/*
Cheapest Flights Within K Stops
Difficulty : Medium

There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, price]
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integer src, dst, and k, return the cheapest price from src to dst with at most k steps. If there is no such route
return -1.

Example :
input n = 4
flights = [[0,1,100], [1,2,100], [2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 0
k = 1
output = 700
explanation:
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> flights(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    vector<pair<int, int>> adj[n];

    for (int i = 0; i < n; i++)
    {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    int src, dst, k;
    cin >> src >> dst >> k;
    // no_of_stops, stop, dist
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int no_stops = it.first;
        int stop = it.second.first;
        int cost = it.second.second;

        if (no_stops > k)
            continue;
        for (auto iter : adj[stop])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            if (cost + edW < dist[adjNode] && no_stops <= k)
            {
                dist[adjNode] = cost + edW;
                q.push({no_stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    cout << dist[dst];
}