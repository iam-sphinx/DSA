#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int b[1000];

    int mid;
    if (n & 1)
    {
        mid = n / 2;
    }
    else
    {
        mid = n / 2 - 1;
    }
    int prev = mid - 1;
    int next = mid + 1;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            b[i] = a[mid];
        }
        else if (i & 1)
        {
            b[i] = a[next];
            next++;
        }
        else
        {
            b[i] = a[prev];
            prev--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}