#include <bits/stdc++.h>
using namespace std;
int findPosition(int a[],int n,int x);


int main()
{
    int a[] = {5,1,2,3,4};
    cout<<findPosition(a,5,1)<<endl;
    return 0;
}
int findPosition(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    if(a[i]==x)
    return i;
    return -1;
}