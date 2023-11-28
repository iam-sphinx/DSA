// Tabulation means bottom up approach ie the base case is handled first
// and then we go to required case

#include<bits/stdc++.h>
using namespace std;


// Time complexity - O(n);
// space complexity - O(n);     for dp array;

int solve(int fib, vector<int> &dp)
{
    // First take care of base case ie handle base case first
    dp[0] = 0;
    dp[1] = 1;

    // now we are going to req case from base see how it goes
    // as we know our loop will start from 2

    for(int i=2; i<=fib; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[fib];

}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);    //initalize a dp same as before;
    int ans = solve(n, dp);
    cout<<ans<<endl;
}