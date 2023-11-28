/* Alice has a wallet with different coins And he also has a magic wand that can create multiple coins. Now Alice wants to buy some stuff of
cost 'K' .Alice want to spend as minimim count of coin as possible can you help him to achieve this. */

#include <iostream>
#include <vector>
using namespace std;

int recSolve(vector<int> &wallet, int target, int idx)
{
    // base case
    if (idx == 0)
    {
        if (target % wallet[0] == 0)
            return target / wallet[0];
        
        return 1e9;     //this will ensure this case is not get counted since we are focusing on minimum now think for maximum ??
    }

    // not taken
    int notTake = 0 + recSolve(wallet, target, idx - 1);
    // take
    int take = INT_MAX;
    if (wallet[idx] <= target)                                  // you will found out when analyze this you will get that if target is less than current wallet[idx] then
    {                                                           // this will not run.
        take = 1 + recSolve(wallet, target - wallet[idx], idx); // we will stand at same index after taking it. this will ensure ∞
    }

    return min(take, notTake);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> wallet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wallet[i];
    }
    int recAns = recSolve(wallet, k, n - 1);
    cout << "Recursive Solution : "<<recAns << endl;
}