#include <bits/stdc++.h>
using namespace std;

bool parenthesisChecker(string s);


int main()
{
    cout << parenthesisChecker("[()]{}{[()()]()") << endl;
    return 0;
}

bool parenthesisChecker(string s)
{
    stack<char> stk;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        stk.push(s[i]);

        else if(!stk.empty())
        {
            if(s[i]=='}'&&stk.top()=='{')
            stk.pop();

            else if (s[i] == ']' && stk.top() == '[')
            stk.pop();

            else if (s[i] == ')' && stk.top() == '(')
            stk.pop();

            else
            return false;
        }
        else
        {
            return false;
        }       
    }
     return stk.empty()?true:false;
}