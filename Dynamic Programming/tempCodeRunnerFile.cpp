/* Continuation of DP-43 now Tabulation part */


#include<iostream>
#include<vector>
using namespace std;

int tabSolve(vector<int> &input, int idx, int prev_idx, vector<vector<int>> &dp)
{

    for(int i = input.size() - 1; i>=0; i--)
    {
        for(int j = i - 1; j >= -1; j--)
        {