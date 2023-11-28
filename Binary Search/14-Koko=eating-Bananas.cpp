/*
    Difficulty : Medium
    Topics : Array, Binary Search

    Problem Statement :
        Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in
        h hours.
        Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
        If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
        Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
        Return the minimum integer k such that she can eat all the bananas within h hours.

    Example 1:
        Input: piles = [3,6,7,11], h = 8
        Output: 4

    Example 2:
        Input: piles = [30,11,23,4,20], h = 5
        Output: 30

    Example 3:
        Input: piles = [30,11,23,4,20], h = 6
        Output: 23
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int findMax(vector<int> &piles)
{
    int maxi = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &piles, int hr)
{
    int totalH = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totalH += ceil((double)piles[i] / (double)hr);
    }
    return totalH;
}

int main()
{
    int n, hr;
    cin >> n >> hr;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int low = 1, high = findMax(piles), ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(piles, mid);
        if (totalH <= hr)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}