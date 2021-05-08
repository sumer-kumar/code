#include <bits/stdc++.h>
using namespace std;


string nextCount(string s);
string countAndSay(int n);

int main(){

    cout<<countAndSay(5)<<endl;
    return 0;
}

string countAndSay(int n)
{
    string str = "1";
    for(int i=1;i<n;i++)
    {   cout<<str<<endl;
        str = nextCount(str);
    }
    return str;
}


//working smoothly
string nextCount(string s)
{ //approach is to use window of same symbols
    int count=0;
    string next="";
    int size = s.size();
    int initial =0;
    // int current = 0;
    int i;
    for(i=0;i<size;i++)
    {
        if(s[initial]==s[i])
        {
            count++;
        }
        else
        {
            next = next + to_string(count)+s[initial];
            initial = i;
            count=1;
        }
    }
    next = next + to_string(count) + s[initial];
    return next;
}
