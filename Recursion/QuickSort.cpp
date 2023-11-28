#include <bits/stdc++.h>
using namespace std;

void QuickSort(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = input[end];
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

    // moving pivot to correct place
    swap(input[start], input[j]);
    pivot = j;

    QuickSort(input, start, pivot - 1);
    QuickSort(input, pivot + 1, end);
}

void printArray(int input[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

int main()
{
    int input[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    QuickSort(input, 0, n - 1);
    printArray(input, n);
}
