/*
Minimum Multiplication to reach End
Difficulty: Medium

Given start, end and an array arr of a n numbers. At each steps, start is multiplied with any number in the array and then mod operation with 
100000 is done to get the new start.
Your taks is to find the minimum steps in which end can be achieved starting from start If it is not possible to reach end, then return -1

Example 1:
    Input:
        arr[] = {2, 5, 7}
        start = 3, end = 30
    output:
        2
    Explanation:
        Step 1: 3*2 = 6 % 1e5 = 6
        Step 2: 6*5 = 30 % 1e5 = 30
*/

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &input, int start, int end)
{
    // no of mul , value after mul
    queue<pair<int, int>> q;
    int mod = 10000;
    q.push({0, start});
    vector<int> dist(10000, 1e9);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        for (auto it : input)
        {
            int num = (it * node) % mod;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({steps + 1, num});
            }
        }
    }
    return -1;
}

int main()
{
    int n, start, end;
    cin >> n >> start >> end;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int ans = solve(input, start, end);
    cout << ans << endl;
    return 0;
}