#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> *vp = new vector<int>();
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);

    v[1] = 100;
    cout<<v[1];
    cout<<v.size();
}