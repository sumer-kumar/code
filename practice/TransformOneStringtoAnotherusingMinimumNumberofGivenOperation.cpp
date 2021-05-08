#include <bits/stdc++.h>
using namespace std;
int minimumTransforms(string original,string s);


int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout<<minimumTransforms(B,A);

    return 0;
}

int minimumTransforms(string original,string s)
{   
    int count = 0;
    queue<char> q;
    for(auto i = s.rbegin();i!=s.rend();i++)
    {
        q.push(*i);
    }

    for(int i=original.size()-1;i>=0;i--)
    {
        while(q.front()!=original[i])
        {
            count++;
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    return count;
}