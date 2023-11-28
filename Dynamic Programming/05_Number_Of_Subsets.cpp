/*Number Of Subsets

Problem Statement ->
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the
array are there such that the sum of chosen elements is equal to the target number "tar".
*/

#include <iostream>
#include <vector>
using namespace std;

// recursive approach
int recSolve(vector<int> &input, int tar, int idx)
{
    if (tar == 0)
    {
        return 1;
    }
    if (idx == 0)
    {
        return (input[idx] == tar);
    }

    int taken = 0;
    if (input[idx] <= tar)
        taken = recSolve(input, tar - input[idx], idx - 1);
    int notTaken = recSolve(input, tar, idx - 1);

    return (taken + notTaken);
}

// memoization solution
int memoSolve(vector<int> &input, int tar, int idx, vector<vector<int>> &dp)
{

    if (tar == 0)
    {
        return 1;
    }
    if (idx == 0)
    {
        return (input[idx] == tar);
    }

    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    int taken = 0;
    if (input[idx] <= tar)
        taken = memoSolve(input, tar - input[idx], idx - 1, dp);
    int notTaken = memoSolve(input, tar, idx - 1, dp);

    return (dp[idx][tar] = taken + notTaken);
}

// tabulation Solution
int tabSolve(vector<int> &input, int tar, int idx, vector<vector<int>> &dp)
{
    // base case
    for (int i = 0; i <= idx; i++)
    {
        dp[i][0] = 1; // this represent all idx whose tar = 0 gives true or 1
    }

    if (input[0] <= tar)
        dp[0][input[0]] = 1; // this will mark that idx where input[0] == tar

    // now going to top
    for (int i = 1; i <= idx; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int taken = 0;
            if (input[i] <= target)
                taken = dp[i - 1][target - input[i]];
            int notTaken = dp[i - 1][target];

            dp[i][target] = taken + notTaken;
        }
    }
    return dp[idx][tar];
}

// space optimized Solution
int spcSolve(vector<int> &input, int tar, int idx)
{
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);

    // base case
    prev[0] = cur[0] = 1;

    if (input[0] <= tar)
        prev[input[0]] = 1; // this will mark that idx where input[0] == tar

    // now going to top
    for (int i = 1; i <= idx; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int taken = 0;
            if (input[i] <= target)
                taken = prev[target - input[i]];
            int notTaken = prev[target];

            cur[target] = taken + notTaken;
        }
        prev = cur;
    }
    return prev[tar];
}

int main()
{
    int n, tar;
    cin >> n >> tar;
    vector<int> input(n);
    vector<vector<int>> memoDp(n, vector<int>(tar + 1, -1));
    vector<vector<int>> tabDp(n, vector<int>(tar + 1, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int recAns = recSolve(input, tar, n - 1);
    cout << "Recursive Solution : " << recAns << endl;

    int memoAns = memoSolve(input, tar, n - 1, memoDp);
    cout << "Memoization Solution : " << memoAns << endl;

    int tabAns = tabSolve(input, tar, n - 1, tabDp);
    cout << "Tabulation Solution : " << tabAns << endl;
    
    int spcAns = spcSolve(input, tar, n - 1);
    cout << "space optimized Solution : " << spcAns << endl;
}
