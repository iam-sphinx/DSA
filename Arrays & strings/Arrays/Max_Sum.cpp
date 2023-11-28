#include <bits/stdc++.h>
using namespace std;

int getMaxSum(int a[], int b[], int n, int m)
{
    int max_sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            sum1 += a[i++];
        }
        else if (a[i] > b[j])
        {
            sum2 += b[j++];
        }
        else
        {
            max_sum = max({sum1, sum2, max_sum});
            i++;
            j++;
        }
    }
    if (i < n)
    {
        for (int x = i; x < n; x++)
        {
            sum3 += a[x];
        }
    }
    if (j < m)
    {
        for (int x = j; x < m; x++)
        {
            sum3 += b[x];
        }
    }
    max_sum = max(sum3, max_sum);
    return max_sum;
}
int main()
{

    int a[1000], b[1000], n, m;
    cout << "enter array 1" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter array 2" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int max_sum = getMaxSum(a, b, n, m);
    cout << "Here is max sum : " << max_sum << endl;
}