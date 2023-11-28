#include <bits/stdc++.h>
using namespace std;
void combinationSum(vector<int> &input, int index, int target, vector<int> &result, vector<vector<int>> &ans)
{
    if (index == input.size())
    {
        if (target == 0)
        {
            ans.push_back(result);
        }
        return;
    }

    if (input.at(index) <= target)
    {
        // selecting index
        result.push_back(input.at(index));
        combinationSum(input, index, target - input.at(index), result, ans);
        result.pop_back();
    }
    // not choosing
    combinationSum(input, index + 1, target, result, ans);
}

int main()
{
    vector<int> result;
    vector<vector<int>> ans;
    int n;
    cin >> n;
    vector<int> input(n);
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int target;
    cin >> target;
    combinationSum(input, 0, target, result, ans);
    cout<<"["<<" ";
    for(auto x:ans)
    {
        cout<<"["<<" ";
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<"]"<<","<<" ";
    }
    cout<<"]";
    cout<<endl;
}