#include <bits/stdc++.h>
using namespace std;
void Merge(int input[], int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
        {
            temp.push_back(input[i]);
            i++;
        }
        else
        {
            temp.push_back(input[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(input[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(input[j]);
        j++;
    }
    int k = 0;
    for (int x = start; x <= end; x++)
    {
        input[x] = temp[k++];
    }
    return;
}

void MergeSort(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(input, start, mid);
    MergeSort(input, mid + 1, end);
    Merge(input, start, mid, end);
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
    MergeSort(input, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}