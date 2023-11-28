/* Best Time To Buy A Stock and Sell it When there is Charge On Each Transaction */
/*Eg - [1,3, 2, 8, 4, 9]  fee = 2*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int recSolve(vector<int> &input, int fee, int idx, int canBuy)
{
    if (idx >= input.size())
    {
        return 0;
    }
    if (canBuy == 1)
    {
        return max(-input[idx] + recSolve(input, fee, idx + 1, 0), recSolve(input, fee, idx + 1, 1));
    }
    return max(input[idx] - fee + recSolve(input, fee, idx + 1, 1), recSolve(input, fee, idx + 1, 0));
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
    int fee;
    cin >> fee;
    int recAns = recSolve(input, fee, 0, 1);
    cout << "Recursive Solution : " << recAns << endl;
}
