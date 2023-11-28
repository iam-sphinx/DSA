#include <bits/stdc++.h>
using namespace std;
void check_unique(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                cout << "Found at index: " << i << " and " << j << " : " << a[i] << " == " << a[j] << endl;
                break;
            }
        }
    }
}

void check_unique_by_sum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int total = n * (n - 1) / 2;
    cout << abs(total - sum) << endl;
}


int main()
{
    int a[1000];
    int n;
    cout << "Enter Count of array" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    check_unique(a, n);
    check_unique_by_sum(a, n);
}