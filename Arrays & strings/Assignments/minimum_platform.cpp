#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Arrival[1000], Dept[1000];
    int n;
    cout<<"enter an array size :"<<endl;
    cin>>n;
    cout<<"enter arrival time :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>Arrival[i];
    }
    cout<<"enter dept time : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>Dept[i];
    }

    int min_plat = 0;
    for(int i=0; i<n; i++)
    {
        if(Arrival[i+1] < Dept[i])
        min_plat++;
    }
    cout<<"minimum platform needed : "<<min_plat<<endl;


}