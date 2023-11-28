/*          0/1 KnapSack        */

/* We are given N items where each item has some weight and profit associated with it. We are also given a bag with capacity W, [i.e., the
bag can hold at most W weight in it]. The target is to put the items into the bag such that the sum of profits associated with them is the
maximum possible.*/

#include <iostream>
#include <vector>
using namespace std;

// recursive approach
int recSolve(vector<vector<int>> &input, int bag_wt, int idx)
{
    if (idx == 0)
    {
        if (input[0][idx] <= bag_wt)
            return input[1][idx];

        return 0;
    }

    // take
    int take = INT_MIN;
    if (input[0][idx] <= bag_wt)
    {
        take = input[1][idx] + recSolve(input, bag_wt - input[0][idx], idx - 1);
    }
    // not take
    int notTake = 0 + recSolve(input, bag_wt, idx - 1);

    return max(take, notTake);
}

// memoization solution
int memoSolve(vector<vector<int>> &input, int bag_wt, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (input[0][idx] <= bag_wt)
            return input[1][idx];

        return 0;
    }

    if (dp[idx][bag_wt] != -1)
        return dp[idx][bag_wt];

    int take = INT_MIN;
    if (input[0][idx] <= bag_wt)
    {
        take = input[1][idx] + memoSolve(input, bag_wt - input[0][idx], idx - 1, dp);
    }
    // not take
    int notTake = 0 + memoSolve(input, bag_wt, idx - 1, dp);

    return dp[idx][bag_wt] = max(take, notTake);
}

//tabulation solution
int tabSolve(vector<vector<int>>& input, int bag_wt, int idx, vector<vector<int>>& dp) {
    // base case
    // For index 0, all the weight less than or equal to weight are accepted
    for (int w = 0; w <= bag_wt; w++) {
        if (input[0][0] <= w) {
            dp[0][w] = input[1][0];
        }
    }

    for (int i = 1; i <= idx; i++) {
        for (int w = 0; w <= bag_wt; w++) {
            int take = INT_MIN;
            if (input[0][i] <= w) {
                take = input[1][i] + dp[i - 1][w - input[0][i]];
            }
            // not take
            int notTake = dp[i - 1][w];

            dp[i][w] = max(take, notTake);
        }
    }
    return dp[idx][bag_wt];
}


int main()
{
    int n, bag_wt;
    cin >> n >> bag_wt;
    vector<vector<int>> input(2, vector<int>(n, 0));
    vector<vector<int>> memoDP(n, vector<int>(bag_wt + 1, -1));
    vector<vector<int>> tabDP(n, vector<int>(bag_wt + 1, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> input[i][j];
    }
    int recAns = recSolve(input, bag_wt, n - 1);
    cout << "Recursive solution : " << recAns << endl;

    int memoAns = memoSolve(input, bag_wt, n - 1, memoDP);
    cout << "Memoization solution : " << memoAns << endl;

    int tabAns = tabSolve(input, bag_wt, n - 1, tabDP);
    cout << "tabulation solution : " << tabAns << endl;
}