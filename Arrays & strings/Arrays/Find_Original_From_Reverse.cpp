#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000];
    int n;
    cout << "Enter no of elements in array" << endl;
    cin >> n;

    cout << "Now Enter reversed array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

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

    int b[1000];

    if (n & 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                b[mid] = a[i];
            }
            else if (i & 1)
            {
                b[prev] = a[i];
                prev--;
            }
            else
            {
                b[next] = a[i];
                next++;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                b[mid] = a[i];
            }
            else if (i & 1)
            {
                b[next] = a[i];
                next++;
            }
            else
            {
                b[prev] = a[i];
                prev--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}