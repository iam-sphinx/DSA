/* You are given an array/list 'ARR' of 'N' positive integers and an integer 'K'. Your task is to check if there exists a subset in 'ARR'
 with a sum equal to 'K'.

NOTE: Return true if there exists a subset with sum equal to 'K'. Otherwise, return false.

for Examlple :
________________________________________________________________________________________________________________________________________________

If 'ARR' is {1, 2, 3, 4} and 'K' = 4, then there exists 2 elements with sum = 4. These are {1, 3} and {4}. Hence,return true.
________________________________________________________________________________________________________________________________________________

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// recursive solution
bool recSolve(vector<int> &ARR, int target, int idx)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (ARR[idx] == target);
    bool take = false;
    if (ARR[idx] <= target)
        take = recSolve(ARR, target - ARR[idx], idx - 1);
    bool notTake = recSolve(ARR, target, idx - 1);

    return (take | notTake);
}

// memoization solution
// TC -> O(N x target)
// SC-> O(N x target) + O(N)
bool memoSolve(vector<int> &ARR, int target, int idx, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (ARR[idx] == target);
    bool take = false;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    if (ARR[idx] <= target)
        take = memoSolve(ARR, target - ARR[idx], idx - 1, dp);
    bool notTake = memoSolve(ARR, target, idx - 1, dp);

    return dp[idx][target] = take | notTake;
}

// tabulation solution
bool tabSolve(vector<int> &ARR, int target, vector<vector<int>> &dp)
{
    int n = ARR.size();

    // base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][ARR[0]] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (ARR[i] == j)
                dp[i][j] = true;
            else if (i > 0)
                dp[i][j] = dp[i - 1][j] || (j - ARR[i] >= 0 ? dp[i - 1][j - ARR[i]] : false);
        }
    }

    return dp[n - 1][target];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ARR(n, 0);
    vector<vector<int>> memoDp(n, vector<int>(k + 1, -1));
    vector<vector<int>> tabDp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> ARR[i];
    }

    bool recAns = recSolve(ARR, k, n - 1);
    cout << "recursion solution :" << recAns << endl;

    bool memoAns = memoSolve(ARR, k, n - 1, memoDp);
    cout << "memoization solution :" << memoAns << endl;

    bool tabAns = tabSolve(ARR, k, tabDp);
    cout << "tabulation solution :" << tabAns << endl;
}