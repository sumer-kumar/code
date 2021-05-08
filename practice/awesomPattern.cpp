#include <bits/stdc++.h>
using namespace std;

int main()
{


    return 0;
}

int checkingMax(char a[],int size,int k)
{
    vector<int> r;
    vector<int> g;
    for(int i=0;i<size;i++)
    {
        if(a[i]=='R')
        {
            r.push_back(i);
        }
        else
        {
            g.push_back(i);
        }   
    }

    //for red max len
    int maxl = 0;
    
    for(int i=0;i<r.size()-1;i++)
    {
        int op = k;
        int curr = 1;
        for(int j = i;j<r.size();j++)
        {
            op = op - (curr - j) 
        }       
    }



}