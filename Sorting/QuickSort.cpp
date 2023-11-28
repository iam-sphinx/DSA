#include <iostream>
#include <vector>
using namespace std;
void QuickSort(vector<int> &input, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = input[start];
    int i = start;
    int j = end;

    while (i <= j)
    {
        if (input[i] <= pivot)
        {
            i++;
        }
        else if (input[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }

    
    swap(input[start], input[j]);
    pivot = j;

    QuickSort(input, start, pivot - 1);
    QuickSort(input, pivot + 1, end);
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

    QuickSort(input, 0, n - 1);
    for (auto x : input)
    {
        cout << x << " ";
    }
}
