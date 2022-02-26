#include <bits/stdc++.h>
using namespace std;
void calLPS(string s,int lps[]);


int main()
{   
    string s = "aaacaaaa";
    int a[20]={0};

    calLPS(s,a);
    return 0;

}

void calLPS(string s,int lps[])
{   
    lps[0] = 0;
    int size = s.size();
    int i = 1 ;
    int len = 0;

    while(i<size)
    {
        if(s[len]==s[i])
        {
            lps[i] = ++len;
            i++;
        }

        else
        {
            if( len !=0)
            {
                len = lps[len-1];
            }

            else 
            {
                lps[i++] = 0;
            }
        }   
    }
}
