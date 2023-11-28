// Subsequence means part just follow order of string.
#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int input[], int end, int start, vector<int> &out)
{
    if (start == end)
    {
        for (auto x : out)
        {
            cout << x << " ";
        }
        cout<<endl;
        return;
    }
    // choice 1 add element
    out.push_back(input[start]);
    printSubsequence(input, end, start + 1, out);
    out.pop_back();
    printSubsequence(input, end, start + 1, out);
    return;
}

int main()
{
    int input[100];
    vector<int> out;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    printSubsequence(input, n, 0, out);
}