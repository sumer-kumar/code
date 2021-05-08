#include <bits/stdc++.h>
using namespace std;
int minBracketReversal(string s);

int main()
{
    cout << minBracketReversal("{{{{}}");

    return 0;
}

int minBracketReversal(string s)
{
    int size = s.size();
    if(size&1)//if size of string is odd then not possible
    return -1;

    stack <char> stk;

    for(int i=0;i<size;i++)
    {
        if(s[i]=='}'&&!stk.empty())
        {
            if(stk.top()=='{')
            stk.pop();

            else
            {
                stk.push(s[i]);
            }
        }
        else
        {
            stk.push(s[i]);
        }

    }

    // cout<<stk.size()<<endl;
    int len = stk.size();
    while(!stk.empty()&&stk.top()=='{')
    stk.pop();

    // cout<<stk.size()<<endl;
    return (stk.size()+1)/2+(len - stk.size()+1)/2;
}