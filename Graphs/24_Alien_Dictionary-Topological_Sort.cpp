/*
    Given a sorted dictionary of an alien language having N words and K starting alphabets of standard dictionary. Find the order of characters
    in the alien language.

    Note : Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of
    string returned by the function is correct else 0 denoting incorrect string returned.

    Alien  k = 4
    baa
    abcd
    abca
    cab
    cad


    intution : make directed graph using statement that who appear before who i.e make pair and make directed graph and using topological sort
    whether possible or not if possible print topo order.

    remember not possible case is (abcd, abc) (basic order of smaller should come first), (abc, baf, ade) (Cycle)

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<string> alienOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> alienOrder[i];
    }

    // now compairing pair to get directed graph
    // remeber we are mapping characters with integer say a -> 0, b -> 1...
    vector<int> adj[k];

    for (int i = 0; i < k - 1; i++)
    {
        string s1 = alienOrder[i];
        string s2 = alienOrder[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo;
    queue<int> q;
    vector<int> inDeg(k, 0);

    for (int i = 0; i < k; i++)
    {
        for (auto it : adj[i])
        {
            inDeg[it]++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            inDeg[it]--;
            if (inDeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    string output = "";

    for (auto it : topo)
    {
        output += char(it + 'a');
    }

    cout << output << endl;
}