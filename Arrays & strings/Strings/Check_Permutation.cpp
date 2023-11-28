#include <bits/stdc++.h>
using namespace std;
void check_Permutation(char input1[], char input2[])
{
    int freq[256] = {0};
    int flag = 0;
    for (int i = 0; input1[i] != '\0'; i++)
    {
        freq[input1[i]]++;
    }
    for (int i = 0; input2[i] != '\0'; i++)
    {
        freq[input2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "Permutation Exists" << endl;
    }
    else
    {
        cout << "Permutation Doesnot Exist" << endl;
    }
}

int main()
{
    char input1[1000], input2[1000];
    cin >> input1 >> input2;
    check_Permutation(input1, input2);
}