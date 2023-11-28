#include <bits/stdc++.h>
using namespace std;

void printPermutation(vector<int> &input, int Map[], vector<vector<int>> &ans, vector<int> ds)
{
    if (ds.size() == input.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (!Map[i])
        {
            Map[i] = 1;
            ds.push_back(input.at(i));
            printPermutation(input, Map, ans, ds);
            ds.pop_back();
            Map[i] = 0;
        }
    }
}
int main()
{
    vector<int> input;
    vector<int> ds;
    vector<vector<int>> ans;

    int Map[100] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    printPermutation(input, Map, ans, ds);
    cout << "[";
    for (auto x : ans)
    {
        cout << "[";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "], ";
    }
    cout << "]";
}