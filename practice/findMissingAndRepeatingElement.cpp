#include <bits/stdc++.h>
using namespace std;
void findMissingAndRepeating(int a[],int n);

int main()
{   int a [] = {1,2,3,3,4,6,7,8};
    findMissingAndRepeating(a,8);

    return 0;
}
void findMissingAndRepeating(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])-1]>0)
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        else
            cout << abs(a[i]) <<" ";
    }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<" ";
    //for missing
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            cout<<(i+1)<<endl;
        }
    }


}