/**/
#include<iostream>
#include<vector>
using namespace std;

int solve(int i, int c, vector<int>&cuts)
{
    
}
int main()
{
    int c;
    cin>>c;
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    input.push_back(c);
    input.insert(input.begin(), 0);

    int ans = solve(1, c, input);
}