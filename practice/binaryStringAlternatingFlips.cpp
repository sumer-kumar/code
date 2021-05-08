#include <bits/stdc++.h>
using namespace std;
int flipsWithStart(string &s,char ch);
char alternate(char ch);
int flips(string &s);

int main()
{
    string s = "001";
    cout<<flips(s);
    return 0;
}

int flips(string &s){
    return min(flipsWithStart(s,'0'),flipsWithStart(s,'1'));
}

int flipsWithStart(string &s,char ch)
{
    int count = 0;
    char first = ch; //i will point to it
    char second = alternate(ch); //j will point to it
    for(int i=0,j=1;i<s.size();i+=2,j+=2)
    {
        if(s[i]!=first)
        count++;
        
        if(s[j]!=second&&j<s.size())
        count++;
    }
    return count;
}

//return alternate of the given character ch
char alternate(char ch)
{
    return ch=='0'?'1':'0';
}