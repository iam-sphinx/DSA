/*Given a knapsack weight W and a set of N items with certain values(benefit or profit) val, and weights wt, find the maximum amount that could 
make up the exact knapsack weight. In Unbounded Knapsack, you may select an item multiple times.*/

#include<iostream>
#include<vector>
using namespace std;

// Recursive Approach
int recSolve(vector<int>&val, vector<int>&wt, int target, int idx)
{

    if(idx == 0)
    {
        return (target / wt[0]) * val[0];
    }

    //not taken
    int notTaken = 0 + recSolve(val, wt, target, idx - 1);
    //taken
    int taken = -1e8;
    if(wt[idx] <= target)
    {
        taken = val[idx] + recSolve(val, wt, target - wt[idx], idx);
    }

    return max(taken, notTaken);

}

// Memoization Approach
int memoSolve(vector<int>&val, vector<int>&wt, int target, int idx, vector<vector<int>> &dp)
{

    if(idx == 0)
    {
       return (target / wt[0]) * val[0];
    }

    if(dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    //not taken
    int notTaken = 0 + memoSolve(val, wt, target, idx - 1, dp);
    //taken
    int taken = -1e8;
    if(wt[idx] <= target)
    {
        taken = val[idx] + memoSolve(val, wt, target - wt[idx], idx, dp);
    }

    return dp[idx][target] =  max(taken, notTaken);

}

// tabulation solution
int tabSolve(vector<int>&val, vector<int>&wt, int target, int idx, vector<vector<int>>&dp)
{

}

int main()
{
    int n;
    int target;
    cin>>n>>target;
    vector<int> val(n);
    vector<int> wt(n);
    vector <vector<int> >memoDP(n, vector<int>(target + 1, -1));
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    int recAns = recSolve(val, wt, target, n-1);
    cout<<"Recursive Solution: "<<recAns<<endl;
    
    int memoAns = memoSolve(val, wt, target, n-1, memoDP);
    cout<<"Memoization Solution: "<<memoAns<<endl;
    
    int tabAns = tabSolve(val, wt, target, n-1, memoDP);
    cout<<"Tabulation Solution: "<<tabAns<<endl;
    
}