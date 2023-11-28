// this is second approach a better one

#include <bits/stdc++.h>
using namespace std;

void printPermutation(vector<int> &input, int pointer)
{
    if (pointer >= input.size())
    {
        for (auto x : input)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    for (int i = pointer; i < input.size(); i++)
    {
        swap(input.at(pointer), input.at(i));
        printPermutation(input, pointer + 1);
        swap(input.at(pointer), input.at(i));
    }
}

int main()
{
    vector<int> input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    printPermutation(input, 0);
}