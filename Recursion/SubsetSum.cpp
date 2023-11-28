#include <bits/stdc++.h>
using namespace std;
void subsetSum(vector<int> input, int idx, int total, vector<int> &sum)
{
    if (idx == input.size())
    {
        sum.push_back(total);   
        return;
    }

    subsetSum(input, idx + 1, total + input.at(idx), sum);
    subsetSum(input, idx + 1, total, sum);
}

int main()
{
    vector<int> input;
    vector<int> sum;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    subsetSum(input, 0, 0, sum);

    sort(sum.begin(), sum.end());
    for(auto x:sum)
    {
        cout<<x<<" ,";
    }

}