#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[1000];
    // in case of char array (strings) we do not need to run for loops we can simply enter a string and output the same.
    //null (\0) will be appended at the end of string as delimeter.
    //keep in mind char array must be size + 1 for null.

    //but keep it in mind we can only take one word (terminate on space)
    //eg. if i write Kandarp Mishra output will be Kandarp only.
    //for a string use cin.getline(char array, input size, delimeter(optional by default \n));
    //keep in mind input size means no of character user types it takes 1 less always than limit last for \0

    cin>>a;
    // cin.getline(a,1000);
    cout<<a;
}