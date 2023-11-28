/*
You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that
the sum of elements in both subsets is equal.

For example, let's say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5] and [3, 3, 4] with equal sum 10.

Follow Up :
Can you solve this using not more than O(S) extra space, where S is the sum of all elements of the given array
*/

/*
This question is bit tricky so let us find out ->
first we are dividing array in 2 equal parts so odd array are out !
now for even case ->
our task is to find out two array of equal size of same sum that means if we add both array there sum will be sum of total COMMON SENSE
so we got our target ie Total Sum / 2 and if we found any subsequence whose sum is half then rest of the half will be also equal.
*/

#include <iostream>
#include <vector>
using namespace std;

void recSolve(vector<int> &ARR, vector<vector<int>> &output, int idx, int sum, vector<int> Temp)
{
    if (ARR.size() & 1)
        return;

    if (idx == 0)
    {
        if (ARR[idx] == sum)
        {
            Temp.push_back(ARR[idx]);
            output.push_back(Temp);
            return;
        }
        else
        {
            return;
        }
    }

    if (sum == 0)
    {
        output.push_back(Temp);
        return;
    }

    // take
    Temp.push_back(ARR[idx]);
    recSolve(ARR, output, idx - 1, sum - ARR[idx], Temp);
    Temp.pop_back();
    // notTake
    recSolve(ARR, output, idx - 1,sum, Temp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> ARR(n, 0);
    vector<vector<int>> recOutput;
    vector<int> Temp;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> ARR[i];
        sum += ARR[i];
    }
    recSolve(ARR, recOutput, n - 1, sum / 2, Temp);
    cout << "[";
    for (auto x : recOutput)
    {
        cout << "[ ";
        for (auto y : x)
        {
            cout << y << ", ";
        }
        cout << "],";
    }
    cout << "]";
}