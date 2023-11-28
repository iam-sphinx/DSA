#include <iostream>
#include <cstring>
using namespace std;

void string_prefix(char ch[])
{
    for (int i = 0; ch[i] != '\0'; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch[j];
        }
        cout << endl;
    }
}

int main()
{
    char string1[1000], string2[1000];
    cin.getline(string1, 50);
    int length = strlen(string1); // inbuilt function to return string length

    cin.getline(string2, 50);
    int check = strcmp(string1, string2); // inbuilt function to compare two string check if else for better visualization
    if (check == 0)
    {
        cout << "both string are equal" << endl;
    }
    else
    {
        cout << "strings are not equal" << endl;
    }
    cout << "here is length : " << length << endl;

    cout << "Original string2 : " << string2 << endl;
    strcpy(string2, string1); // inbuilt function to source string to destination strcpy(dest,source)
    cout << "Changed string2 : " << string2 << endl;

    strncpy(string2, "voila", 2); // inbuilt function to copy upto limits it will not copy null character
    cout << string2 << endl;

    // special case where n is greater it will append null at remaining pos
    strncpy(string2, "hello", 6);
    cout << string2 << endl;

    // print prefix
    string_prefix(string1);
}