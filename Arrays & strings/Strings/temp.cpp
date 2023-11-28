#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
    int n;
    cin>>n;
    string s;
    cin>>s;
    int j = -1;
    for(int i=0; i<n-2; i++)
    {
        if(s[i] == '1')
        {
            j = i;
            break;
        }
    }
    if(j != -1)
    {
        for(int i=j + 1; i<n;i++)
        {
            s[i] = '0';
        }
    }
    cout<<s<<endl;
     
    }
}