#include<bits/stdc++.h>
using namespace std;

int main()
{
    int input[1000];
    int n;
    cout<<"enter array : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    int  nonZero = 0;
    for(int i=0; i<n; i++)
    {
        if(input[i] != 0)
        {
            swap(input[nonZero], input[i]);
            nonZero++;
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}