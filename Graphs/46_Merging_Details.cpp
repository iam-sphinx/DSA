/*
    Merging Details

    Bob, a teacher of St. Joseph school given a task by his principal to merge the details of the student where each element detail[i] is a
    list of strings, where the first details[i][0] is a name of the student. Two details definitely belong to the same student if there is
    some common email to both detail. After merging the details, return the details of the student in the following format. The first element
    of each detail is the name of the student, and the rest of the elements are emails in sorted order. The details themselves can be returned
    in any order. Note: Two details have the same name, they may belong to different people as people could have the same name. A person can
    have any number of details initially, but all of their details definitely have the same name.

    Note : In case 2 or more same email belongs to 2 or more different names merge with first name only. Print in the order in sorted way
    according to the name of the detials

    Example 1 :
    Input:
        n: 4
        details =
        [["John","johnsmith@mail.com","john_newyork@mail.com"],
        ["John","johnsmith@mail.com","john00@mail.com"],
        ["Mary","mary@mail.com"],
        ["John","johnnybravo@mail.com"]]

    Output:
        [["John","john00@mail.com","john_newyork@mail.com",
        "johnsmith@mail.com"],["Mary","mary@mail.com"],
        ["John","johnnybravo@mail.com"]]

    Explanation:
        The first and second John's are the same person as
        they have the common email "johnsmith@mail.com".
        The third John and Mary are different people as none
        of their email addresses are used by other accounts.
        We could return these lists in any order, for example
        the answer [['Mary', 'mary@mail.com'],
        ['John', 'johnnybravo@mail.com'],
        ['John', 'john00@mail.com', 'john_newyork@mail.com',
        'johnsmith@mail.com']]
        would still be accepted.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "DisjointSet.cpp"

using namespace std;
vector<vector<string>> mergeDetails(vector<vector<string>> &details)
{
    int n = details.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    vector<string> mergeList[n];
    for(auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUlpParent(it.second);

        mergeList[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for(int i=0; i<n; i++)
    {
        if(mergeList[i].size() == 0) continue;

        sort(mergeList[i].begin(), mergeList[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);

        for(auto it : mergeList[i])
        {
            temp.push_back(it);
        }

        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> details;
    while (n--)
    {
        int m;
        cin >> m;
        vector<string> temp;
        while (m--)
        {
            string data;
            cin >> data;
            temp.push_back(data);
        }
        details.push_back(temp);
    }

    vector<vector<string>> output = mergeDetails(details);

    for (auto it : output)
    {
        for (auto y : it)
        {
            cout << y << " ,";
        }
        cout << endl;
    }
}