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

    vector<int> dp(n, 1), cnt(n, 1);
    int maxi =0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (input[prev] < input[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                // keep same
                cnt[i] = cnt[prev];
            }
            else if (input[prev] < input[i] && 1 + dp[prev] == dp[i])
            {
                // increasr
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int nos = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] == maxi) nos += cnt[i];

    }
    return nos;
}