#include <bits/stdc++.h>
using namespace std;

int searchSTEP(int [],int,int,int);

int main()
{
    int a[] = {1,3,5,7,7,7,8,10,9,7,5,3,2};
    cout<<searchSTEP(a,sizeof(a)/sizeof(a[0]),2,2);
    return 0;
}

int searchSTEP(int a[],int size,int x,int k)
{   cout<<size<<endl;
    for(int i=0;i<size;)
    {
        if(a[i]==x)
        return i;
        i+=max(1,abs(a[i]-x)/k);
    }
    return -1;
}