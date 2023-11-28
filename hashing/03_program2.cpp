/*CHARACTER HASHING*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int hash[26] = {0};
    for(int i=0; i<n; i++)
    {
        int idx = arr[i] - 'a';
        hash[idx]++;
    }
    for(int i=0; i<n; i++)
    {
        int idx = arr[i] - 'a';
        cout<<arr[i]<<" "<<hash[idx]<<endl;;
    }
}