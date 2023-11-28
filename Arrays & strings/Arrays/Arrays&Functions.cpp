#include <bits/stdc++.h>
using namespace std;
void test(int a, int b[])
{
    cout << a << endl;
    cout << b[0]<<endl;
}

void printArray (int input[])
{
    

}

int main()
{

    int input[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int a = 6;
    test(a, input);

    printArray(input);
}
