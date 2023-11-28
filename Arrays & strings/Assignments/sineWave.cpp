#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input[100][100];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> input[i][j];
    }

    cout << "Original 2D Array :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sine 2D Array" << endl;

    for (int j = 0; j < m; j++)
    {
        if (j & 1)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << input[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << input[i][j] << " ";
            }
            cout << endl;
        }
    }
}