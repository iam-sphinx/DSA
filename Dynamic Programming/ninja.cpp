/* Ninja is planning the 'N' days long training schedule. Each day he can perform any of these three activites (running, fighting, training)
each activity has some units points. On each day, As ninja has to improve his skills he can't do the same excercise in two consecutive days
.Can you help ninja find out the maximum merit point. You are given 2D array of size N*3 'points' with the points coresponding to each day end
activity.Your task is to calculate max point ninja can get. */

#include <iostream>
#include <vector>
using namespace std;

// Reccurence Approach
int recSolve(vector<vector<int>> &days, int day_idx, int activity_idx)
{
    if (day_idx == 0)
    {
        int max_activity = INT_MIN;
        for (int j = 0; j < 3; j++)
        {
            if (j != activity_idx)
            {
                max_activity = max(max_activity, days[day_idx][j]);
            }
        }
        return max_activity;
    }

    int max_activity = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if (j != activity_idx)
        {
            int activity = days[day_idx][j] + recSolve(days, day_idx - 1, j);
            max_activity = max(max_activity, activity);
        }
    }
    return max_activity;
}

// memoization solution
int memoSolve(vector<vector<int>> &days, vector<vector<int>> &dp, int day_idx, int activity_idx)
{
    if (day_idx == 0)
    {
        int max_activity = INT_MIN;
        for (int j = 0; j < 3; j++)
        {
            if (j != activity_idx)
            {
                max_activity = max(days[day_idx][j], max_activity);
            }
        }
        return max_activity;
    }
    if (dp[day_idx][activity_idx] != -1)
        return dp[day_idx][activity_idx];

    int max_activity = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if (j != activity_idx)
        {
            int activity = days[day_idx][j] + memoSolve(days, dp, day_idx - 1, j);
            max_activity = max(max_activity, activity);
        }
    }
    return dp[day_idx][activity_idx] = max_activity;
}

// tabulation method
int tabSolve(vector<vector<int>> &days, vector<vector<int>> &dp, int day_idx, int activity_idx)
{
    // base cases
    dp[0][0] = max(days[0][1], days[0][2]);
    dp[0][1] = max(days[0][0], days[0][2]);
    dp[0][2] = max(days[0][0], days[0][1]);
    dp[0][3] = max(days[0][0], max(days[0][1], days[0][2])); // this is first case think about it

    // now going to top
    for (int day = 1; day <= day_idx; day++)
    {
        // each day is associated with last taks
        for (int last = 0; last < 4; last++) // think why 4 not 3
        {
            int max_activity = INT_MIN;
            // now normal task for day given last
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int activity = days[day][task] + dp[day - 1][task];
                    max_activity = max(max_activity, activity);
                }
            }
            dp[day][last] = max_activity;
        }
    }
    return dp[day_idx][activity_idx];
}

// space optimization
int spaceOptSolve(vector<vector<int>> &days, int day_idx)
{
    vector<int> prevState(4, 0);
    // initial state
    prevState[0] = max(days[0][1], days[0][2]);
    prevState[1] = max(days[0][0], days[0][2]);
    prevState[2] = max(days[0][0], days[0][1]);
    prevState[3] = max(days[0][0], max(days[0][1], days[0][2]));

    for (int day = 1; day <= day_idx; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], days[day][task] + prevState[task]);
                }
            }
        }
        prevState = temp;
    }

    return prevState[3];
}
int main()
{
    int n;
    cout << "Enter no of days: " << endl;
    cin >> n;
    vector<vector<int>> days(n, vector<int>(3));
    vector<vector<int>> memoDp(n, vector<int>(4, -1));
    vector<vector<int>> tabDp(n, vector<int>(4, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> days[i][j];
        }
    }

    int recAns = recSolve(days, n - 1, 3);
    cout << "Reccurence Solution: " << recAns << endl;
    int memoAns = memoSolve(days, memoDp, n - 1, 3);
    cout << "Memoization Solution: " << memoAns << endl;
    int tabAns = tabSolve(days, tabDp, n - 1, 3);
    cout << "Tabulation Solution: " << tabAns << endl;
    int spaceOptAns = spaceOptSolve(days, n - 1);
    cout << "space optimised Solution: " << spaceOptAns << endl;
}