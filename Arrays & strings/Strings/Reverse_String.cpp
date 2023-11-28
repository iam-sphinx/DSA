#include <bits/stdc++.h>
using namespace std;

void print_reverse(char input[], int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        cout << input[i];
    }
    cout << endl;
}

int main()
{
    char input[1000];
    cin.getline(input, 500);
    int len = strlen(input);
    print_reverse(input, len);
}