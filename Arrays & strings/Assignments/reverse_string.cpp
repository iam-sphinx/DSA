#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int length = s.length();
    length--;

    for(int i=0 ; i<=length/2; i++)
    {
        swap(s[i], s[length-i]);
    }

    // int checkpost = 0;
    // int start = 0;
    // for(int i=0; i<=length; i++)
    // {
    //     if(s[i] != ' ')
    //     {
    //         checkpost++;
    //     }
    //     else
    //     {
    //         for(int j=start; j<= checkpost/2; j++)
    //         {
    //             swap(s[j], s[checkpost-start-j-1]);
    //         }
    //         start = checkpost++;
    //     }

    // }

    int checkpost = 0;
    int start = 0;
    for(int i=0; i<=length; i++)
    {
        if(s[i] != ' ')
        {
            checkpost++;
        }
        else
        {
            for(int j=start; j<=checkpost/2; j++)
            {
                swap(s[j], s[checkpost-start-j-1]);
            }
            start = checkpost+1;
        }
    }

    cout<<s;
}