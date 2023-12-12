#include<iostream>
#include<vector>

using namespace std;

int main()
{

    int n,m;
    cin>>n>>m;

    // Space complexity O(2 * E)
    vector<int> adj[n + 1];
    while(m--)
    {
        int u,v;
        cin>>u,v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}