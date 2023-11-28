#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<char> &check, int i, int j)
{
    while (i < j)
    {
        if (check[i] != check[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Recursive Approach
int recSolve(vector<char> &input, int idx)
{
    if (idx == input.size())
    {
        return 0;
    }

    int mini = 1e9;
    for (int i = idx; i < input.size(); i++)
    {

        if (canPartition(input, idx, i))
        {
            int cost = 1 + recSolve(input, i + 1);
            mini = min(mini, cost);
        }
    }
    return mini;
}

// Memoization Approach
int memoSolve(vector<char> &input, int idx, vector<int> &dp)
{
    if (idx == input.size())
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int mini = 1e9;
    for (int i = idx; i < input.size(); i++)
    {
        if (canPartition(input, idx, i))
        {
            int cost = 1 + memoSolve(input, i + 1, dp);
            mini = min(cost, mini);
        }
    }
    return dp[idx] = mini;
}

// Tabulation Approach
int tabSolve(vector<char> &input, int idx, vector<int> &dp)
{
    for (int i = input.size() - 1; i >= 0; i--)
    {
        int mini = 1e9;
        for (int j = i; j < input.size(); j++)
        {
            if (canPartition(input, i, j))
            {
                int cost = 1 + dp[j + 1];
                mini = min(cost, mini);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<char> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // Recursive Ans
    int recAns = recSolve(input, 0);
    cout << "Recursive Solution : " << recAns - 1 << endl;

    // Memoization Ans
    vector<int> mempDP(n + 1, -1);
    int memoAns = memoSolve(input, 0, mempDP);
    cout << "Memoization Solution : " << memoAns - 1 << endl;
  
    // Tabulation Ans
    vector<int> tabDP(n + 1, 0);
    int tabAns = tabSolve(input, 0, tabDP);
    cout << "Tabulation Solution : " << tabAns - 1 << endl;
    return 0;
}
