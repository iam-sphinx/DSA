/*MAP STL*/
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,int> mpp;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    int q;
    cin>>q; 
    while(q--)
    {
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
}