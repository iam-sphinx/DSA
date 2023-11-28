/* Longest Increasing Subsequence using Binary Search */
// Eg - [1 7 8 4 5 6 -1 9]

#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for lower_bound
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> temp;
    temp.push_back(input[0]);
    for (int i = 1; i < n; i++)
    {
        if (input[i] > temp.back())
        {
            temp.push_back(input[i]);
        }
        else
        {
            // Find the position to insert the element using lower_bound
            int ind = lower_bound(temp.begin(), temp.end(), input[i]) - temp.begin();
            // Insert the element at the calculated index
            temp[ind] = input[i];
        }
    }
    // The 'temp' vector now contains the Longest Increasing Subsequence
    cout << "Length of Longest Increasing Subsequence: " << temp.size() << endl;
    return 0;
}
