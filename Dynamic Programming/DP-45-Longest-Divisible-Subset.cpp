/* Longest Divisible Subset */
// eg [1 16 7 8 4]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int lastIndex = 0;
    sort(input.begin(), input.end());
    for(int i=0; i<n; i++)
    {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++)
        {
            if(input[i] % input[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(input[lastIndex]);
    while(hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(input[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for(int x : temp)
    {
        cout<<x<<" ";
    }
}