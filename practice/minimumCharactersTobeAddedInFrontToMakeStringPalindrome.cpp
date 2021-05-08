#include <bits/stdc++.h>
using namespace std;
void calLPS(string &s,int lps[]);
int getMinCharToAddedToMakeStringPalin(string s);

int main()
{
    cout << getMinCharToAddedToMakeStringPalin("ABC") << endl;
    return 0;
}

void calLPS(string &s,int lps[])
{
    lps[0]= 0;
    int i = 1;
    int length = 0;
    
    while(i<s.size())
    {
        if(s[length] == s[i])
        {
            lps[i] = ++length;
            i++;
        }
        else //when not matches
        {
            if(length!=0) 
            {
                length = lps[length-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int getMinCharToAddedToMakeStringPalin(string str)
{
    string s = str;
    s+="#"+str;
    cout<<s<<endl;
    int lps[s.size()] = {0};
    calLPS(s,lps);
    return str.size()-lps[s.size()-1];
}