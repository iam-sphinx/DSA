#include<bits/stdc++.h>
using namespace std;

// Now we are optimizing space complexity

// Time Complexity - O(n)
// Space Complexity - O(1);
int solve( int fib)
{
     int prev2 = 0;
    int prev = 1;
    int cur_i;
    for(int i=2; i<=fib; i++)
    {
        cur_i = prev + prev2;
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int main()
{
   int n;
   cin>>n;
   int ans = solve(n);
   cout<<ans;
}