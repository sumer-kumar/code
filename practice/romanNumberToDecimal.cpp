#include <bits/stdc++.h>
using namespace std;
int value(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default: return -1;
    }

}
// string s = "MCMIV";
int romanToDecimal(string &s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int x = value(s[i]);
        if (i + 1 < s.size())
        {
            int y = value(s[i + 1]);
            if (x>=y)
                res += x;
            else
                {res += y - x;
                i++;}
        }
        else
        {
            res += x;
        }
    }
    return res;
}

int main()
{
    string s = "MCMIV";
    cout<<romanToDecimal(s)<<endl;

    return 0;
}

