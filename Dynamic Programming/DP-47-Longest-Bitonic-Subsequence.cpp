/* Longest Bitonic Subsequence */
// increase then decrease
//input => [1 11 2 10 4 5 2 1]
//output => 6

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (input[prev] < input[i] && 1 + dp1[prev] > dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
            }
        }
    }

    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (input[prev] < input[i] && 1 + dp2[prev] > dp2[i])
            {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    int maxi = 0;
    for(int i=0; i<n;i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    cout<<maxi;
}