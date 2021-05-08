#include <bits/stdc++.h>
using namespace std;
string removeSimilarAdacent(string s);

int main()
{
    cout<<removeSimilarAdacent("aaaavvvbbbbbcddddvdbb")<<endl;
    return 0;
}

string removeSimilarAdacent(string s)
{   
    
    string res = "";
    res.push_back(s[0]);
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]!=s[i])
        res.push_back(s[i]);             
    }
    return res;
}