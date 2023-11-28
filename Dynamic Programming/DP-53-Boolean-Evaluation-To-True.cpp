

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach
int recSolve(vector<char> &input, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return input[i] == 'T';
        }
        return input[i] == 'F';
    }

    int total_ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int left_true = recSolve(input, i, ind - 1, true);
        int right_true = recSolve(input, ind + 1, j, true);
        int left_false = recSolve(input, i, ind - 1, false);
        int right_false = recSolve(input, ind + 1, j, false);

        if (input[ind] == '&')
        {
            if (isTrue)
            {
                total_ways += left_true * right_true;
            }
            else
            {
                total_ways += (left_true * right_false) + (left_false * right_true) + (left_false * right_false);
            }
        }

        if (input[ind] == '|')
        {
            if (isTrue)
            {
                total_ways += (left_true * right_true) + (left_false * right_true) + (left_true * right_false);
            }
            else
            {
                total_ways += left_false * right_false;
            }
        }

        if (input[ind] == '^')
        {
            if (isTrue)
            {
                total_ways += (left_false * right_true) + (left_true * right_false);
            }
            else
            {
                total_ways += (left_false * right_false) + (left_true * right_true);
            }
        }
    }
    return total_ways;
}

int main()
{
    int n;
    cin >> n;
    vector<char> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // Recursive Solution
    int recAns = recSolve(input, 0, n - 1, true);
    cout << "Recursive Solution : " << recAns << endl;
    return 0;
}