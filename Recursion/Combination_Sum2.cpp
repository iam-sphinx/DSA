/*Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in
candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.*/
/*Eg.

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.*/

#include <bits/stdc++.h>
using namespace std;

void Combination_Sum2(vector<int> &input, int idx, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < input.size(); i++)
    {
        if (i > idx && input[i] == input[i - 1])
        {
            continue;
        }

        if (input[i] > target)
        {
            break;
        }

        ds.push_back(input[i]);
        Combination_Sum2(input, i + 1, target - input[i], ds, ans);
        ds.pop_back();
    }
}

int main()
{
    vector<int> ds;
    vector<vector<int>> ans;

    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int target;
    cin >> target;

    sort(input.begin(), input.end()); // Sort the input array to handle duplicates
    Combination_Sum2(input, 0, target, ds, ans);

    // Print the result
    cout << "[";
    for (auto x : ans)
    {
        cout << "[";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
