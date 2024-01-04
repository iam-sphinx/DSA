/*
    Floyd Warshal Algorithm (multiple source shortest path algorithm)
    * can also detect negative cycle
    Note -> Go via every vertex/nodes.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>cost[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0 ;j<n; j++)
        {
            if(cost[i][j] == -1)
            {
                cost[i][j] = 1e9;
            }
            if(i == j)
            {
                cost[i][j] = 0;
            }
        }
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
            }
        }
    }

    for (auto it : cost)
    {
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}