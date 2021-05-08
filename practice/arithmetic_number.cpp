#include <bits/stdc++.h>
using namespace std;
bool isPresent(int,int,int);
int main()
{
    cout<<isPresent(0,3,2);
    return 0;
}

bool isPresent(int a0,int aN,int d)
{
        if(a0==aN) return 1;
    if(d==0) return 0;
    if(a0>aN&&d>0)
    return false;
    
    if(a0<aN&&d<0) return 0;
    
    int n = (aN-a0)/d;
    return (a0+n*d)==aN?true:false;
}