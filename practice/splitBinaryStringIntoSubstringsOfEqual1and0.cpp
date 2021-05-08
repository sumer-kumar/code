#include <bits/stdc++.h>
using namespace std;


int countRequredSubstrings(string s);

int main()
{
    cout << countRequredSubstrings("0100110101")<<endl;

    return 0;
}

int countRequredSubstrings(string s)
{
    int size = s.length();
    int count = 0;
    int count1,count0;
    count0=count1=0;
    for(int i=0;i<size;i++)
    {
        s[i]=='0'?count0++:count1++;
        if(count0==count1)
        count++;
    }
    return count>0?count:-1;
}