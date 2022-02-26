#include <bits/stdc++.h>
using namespace std;
void calLPS(string s, int lps[]);
vector <int> kmp(string text,string pat);

int main()
{
    string txt = "AAAAABAAABA";
    string pat = "AAA";

    vector<int> occurs = kmp(txt,pat);
    
    // cout<<occurs.size()<<endl;

    for(int i = 0; i<occurs.size();i++)
    {
        cout<<"["<<occurs[i]<<"]"<<" ";
    }

    return 0;
}

void calLPS(string s, int lps[])
{
    lps[0] = 0;
    int size = s.size();
    int i = 1;
    int len = 0;

    while (i < size)
    {
        if (s[len] == s[i])
        {
            lps[i] = ++len;
            i++;
        }

        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }

            else
            {
                lps[i++] = 0;
            }
        }
    }
}

vector <int> kmp(string text,string pat)
{
    int sizet = text.size();
    int sizep = pat.size();

    int lps[sizep] = {0};

    calLPS(pat,lps);

    int i=0; //for index text
    int j=0; //for index pat
// gvg
    vector<int> occurs;
    while(i<sizet)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j==sizep)
        {
            occurs.push_back(i-j);
            j = lps[j-1];    
        }

        else if(i<sizet && text[i]!=pat[j])
        {
            if(j!=0)
            {
                j = lps[j-1];
            }

            else //if j==0 
            {
                i++;
            }
        }
    }
    return occurs;
}
