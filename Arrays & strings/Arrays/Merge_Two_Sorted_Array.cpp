#include <bits/stdc++.h>
using namespace std;
void merge_Two_Sorted_Array(int a[], int b[], int x, int y, int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < x && j < y)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (j < y)
    {
        c[k++] = b[j++];
    }

    while (i < x)
    {
        c[k++] = a[i++];
    }
}

int main()
{
    int a[1000], b[1000], c[2000] = {0};
    int x, y;
    cout << "Enter first array size" << endl;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    cout << "Enter second array size" << endl;
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
    }

    merge_Two_Sorted_Array(a, b, x, y, c);
    for (int i = 0; i < (x + y); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}