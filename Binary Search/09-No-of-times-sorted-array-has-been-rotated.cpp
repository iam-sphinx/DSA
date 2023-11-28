/*
    Difficulty - Medium
    Topic - Array, Binary Search

    Problem Statement - You have given an array which was initailly sorted but after few rotation it is not rotated n times. Your task is to return how many times does a array has been rotated.

    Logic - the index at which minimum value is placed will be the answer think about that
*/

#include <iostream>
#include <vector>
using namespace std;

int rotationCount(vector<int> &input)
{
    int min_val = INT_MAX;
    int indx = 0;
    int low = 0;
    int high = input.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (input[low] <= input[mid])
        {
            if (min_val > input[low])
            {
                min_val = input[low];
                indx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (min_val > input[mid])
            {
                min_val = input[mid];
                indx = mid;
            }
        }
    }
    return indx;
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

    cout << rotationCount(input) << endl;
}