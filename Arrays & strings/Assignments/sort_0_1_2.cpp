#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input[1000];
    int n;
    cout << "Enter array : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int start = 0;
    int end = n - 1;
    int current = 0;
    while (current != end)
    {
        if(input[current] == 1)
        {
            current ++;
        }
        else if(input[current] == 0)
        {
            swap(input[current], input[start]);
            current++;
            start++;
        }
        else
        {
            swap(input[current], input[end]);
            end--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
}