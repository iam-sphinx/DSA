/*
    Difficulty : Hard
    Topics : Array, Binary Search

    Problem Statement :
        Given an array 'arr' of integer numbers. 'arr[i]' represent number of pages in the i'th book.

        There are 'm' number of students. and the task is to allocate all the books to the students.

        Allocate books in such a way that :
            * Each student gets at least one book.
            * Each book should be allocated to only one student.
            * Book Allocation should be in a contiguous manner.

        You have to allocate the books to 'm' students such that the maximum number of pages assigned to a student is minimum.
        If the allocation of books is not possible return -1.

*/

#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long pCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pCount + arr[i] <= pages)
        {
            pCount += arr[i];
        }
        else
        {
            pCount = arr[i];
            students += 1;
        }
    }
    return students;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = arr[0];
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        low = max(arr[i], low);
        high += arr[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int stud = countStudents(arr, mid);

        if (stud > m)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << low << endl;
}