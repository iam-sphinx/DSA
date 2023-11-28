#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string &s, int start, int end)
{
    if (start >= end)
        return true;
    if (s.at(start) != s.at(end))
    {
        return false;
    }
    checkPalindrome(s, start + 1, end - 1);
}

int main()
{
    string s;
    cin >> s;
    int length = s.length();
    if (checkPalindrome(s, 0, length - 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}