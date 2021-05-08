#include <bits/stdc++.h>
using namespace std;

bool rotationCheck(string rotated,string original);

int main()
{
    string s ="sumer";
    string p = "mersu";
    cout<<rotationCheck(p,s)<<endl;

    // cout<<p<<endl;
    return 0;
}

bool rotationCheck(string rotated,string original)
{
    rotated+=rotated;
    // cout<<rotated<<endl;
    return rotated.find(original)<0?false:true;
}