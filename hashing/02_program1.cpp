#include<bits/stdc++.h>
using namespace std;
// max size of array inside main is 1e6 and for outside (global) is 1e7

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int hash[13] = {0};
    for(int i=0; i<n; i++)
    {
        hash[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;

        cout<<hash[number]<<"\n";
    }
}
