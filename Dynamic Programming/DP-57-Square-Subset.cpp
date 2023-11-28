#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> input(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = input[i][0];
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = input[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(input[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
        }
    }

    int ans = 0;
    for (auto x : dp)
    {
        for (auto y : x)
        {
            ans += y;
        }
    }
    cout << ans << endl;
}