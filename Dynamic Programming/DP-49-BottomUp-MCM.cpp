// Bottom Up Approach

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

    // tabulation
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i=0; i<n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = input[i - 1] * input[k] * input[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    cout<< dp[1][n - 1];
    return 0;
}