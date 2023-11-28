#include <bits/stdc++.h>
using namespace std;

bool printSubsequenceSum(int input[], int start, int end, int sum, vector<int> ds)
{
    if (start == end)
    {
        if (sum == 2)
        {
            for (auto x : ds)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(input[start]);
    sum += input[start];

    if (printSubsequenceSum(input, start + 1, end, sum, ds) == true)
        return true;

    ds.pop_back();
    sum -= input[start];
    if (printSubsequenceSum(input, start + 1, end, sum, ds) == true)
        return true;

    return false;
}

int main()
{
    int input[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int sum = 0;
    vector<int> ds;
    bool ans = printSubsequenceSum(input, 0, n, sum, ds);
}