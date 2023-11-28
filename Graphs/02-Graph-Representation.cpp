/* How to represent a Graph in code Let's find out

   Generally :
        input : n (no of nodes) m (no of edges)
        and then m lines
        representing edges between nodes like
        1 2 (represent a edge between node 1 and node 2)
        it can be in reverse order too 2 1 makes same sense does it

        1 2
        1 3
        2 4
        3 4
        3 5
        4 5

   How to Store ?
    there are two ways :
        1> Adjacancy Matrix
        2> List

    1> Adjacency Matrix
        adj[n + 1][n + 1]

        eg for n = 5
            adj[6][6] is created;

            Representation
                0   1   2   3   4   5

            0   0   0   0   0   0   0

            1   0   0   1   1   0   0

            2   0   1   0   0   1   0

            3   0   1   0   0   1   1

            4   0   0   1   1   0   1

            5   0   0   0   1   1   0
        
        space used = O(N * N)


    2> List
        vector<int>adjList[n + 1]
            0
            1   -> {2,3}
            2   -> {1, 4 5}
            3   -> {1, 4}
            4   -> {3, 2, 5}
            5   -> {2, 4}

        space used = O(2*E)
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // adjacancy matrix
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    //list
    vector<int>adjList[n + 1];
    vector<vector<int>>input(m, vector<int>(2));
    for(int i=0; i<m; i++)
    {
        cin>>input[i][0];
        cin>>input[i][1];
    }
    for(int i=0; i<m; i++)
    {
        int u = input[i][0];
        int v = input[i][1];

        adj[u][v] = 1;
        adj[v][u] = 1;

        // List 
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(auto x : adj)
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}