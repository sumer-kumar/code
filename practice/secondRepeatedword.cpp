#include <bits/stdc++.h>
using namespace std;
string secondMostRepeated(string a[],int size);


int main()
{
    string a[] = {"ccc", "aaa", "ccc","ddd", "aaa", "aaa"};

    cout<<secondMostRepeated(a,6)<<endl;
    return 0;
}

string secondMostRepeated(string a[],int size)
{
    unordered_map<string , int> um;
    for(int i=0;i<size;i++)
    um[a[i]]++;

    int first = INT_MIN;
    int second = INT_MAX;

    for(auto i = um.begin();i!=um.end();i++)
    {
        if(i->second>first)
        {
            second = first;
            first = i->second;
        }
    else if(i->second > second &&i->second!=first)
            second = i->second; 
    }
    for (auto i = um.begin(); i != um.end(); i++)
    {
        if(i->second == second)
        return i->first;
    }
}