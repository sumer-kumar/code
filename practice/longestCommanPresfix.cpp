#include <bits/stdc++.h>
using namespace std;


string lcp(vector<string> & str);

int main()
{
    vector<string> v = {"sumer","summer","sum","sumer"};
    cout<<lcp(v)<<endl;

    return 0;
}

string lcp(vector <string> & str)
{
    string pre = str[0];

    for(int i=0;i<str.size();i++)
    {
        while(str[i].find(pre)!=0)
        {
            pre = pre.substr(0,pre.length()-1);
            if(pre.empty())
            pre;
        }
    }
    return pre;
}