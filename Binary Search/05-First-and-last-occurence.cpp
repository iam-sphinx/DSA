/*
  Problem Statement :
    You have been given a sorted array/list ARR consisting of 'N' elements. You are also given an integer 'k'.Now, your task is to find the first and last occurence of 'k' in ARR.
  Note :
        1. If 'k' is not present in the array, then the first and the last occurence will be -1.
        2. ARR may contains duplicate elements.
    For example:
        if ARR = [0, 1, 1, 5] and k = 1, then the first and last occurence of 1 will be 1 (0-indexed) and 2
*/

#include <bits/stdc++.h>
using namespace std;
void lBound(vector<int> &input, int &lowerBound, int find, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int mid = (low + high) / 2;
    if (input[mid] >= find)
    {
        lowerBound = mid;
        lBound(input, lowerBound, find, low, mid - 1);
    }
    else
    {
        lBound(input, lowerBound, find, mid + 1, high);
    }
}

void uBound(vector<int> &input, int &upperBound, int find, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int mid = (low + high) / 2;
    if (input[mid] > find)
    {
        upperBound = mid;
        uBound(input, upperBound, find, low, mid - 1);
    }
    else
    {
        uBound(input, upperBound, find, mid + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int find;
    cin >> find;
    int lowerBound = -1;
    int upperBound = -1;
    lBound(input, lowerBound, find, 0, n - 1);
    uBound(input, upperBound, find, 0, n - 1);

    if (lowerBound == n || input[lowerBound] != find)
    {
        cout << "[-1, -1]" << endl;
    }
    else
    {
        cout << "[" << lowerBound << ", " << upperBound - 1 << "]" << endl;
    }
}