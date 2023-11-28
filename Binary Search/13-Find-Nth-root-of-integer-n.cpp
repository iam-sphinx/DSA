/* Find the nth root of a number m */

#include <iostream>
#include <math.h>
using namespace std;

int mul(int n, int x, int m)
{
    long long ans = 1;
    while (n--)
    {
        ans *= x;
    }
    if(ans > m)
    {
        return 2;
    }
    if(ans == m)
    {
        return 1;
    }
    return 0;
}

int nthRoot(int n, int m)
{
    int low = 1;
 
    int high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mul(n, mid, m) == 1)
        {
            return mid;
        }

        if(mul(n, mid, m) == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << nthRoot(n, m) << endl;
}
