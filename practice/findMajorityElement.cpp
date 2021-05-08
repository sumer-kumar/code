//well we can easily do it by mapping
//with time comp. o(n) and space o(n)
//but i wanna do it eith o(1) space complexity
#include <bits/stdc++.h>
using namespace std;

int findmajority(int a[],int n);


int main()
{
    int a[] = {1,2,1,3,1,4,1,5,1};
    cout<<findmajority(a,sizeof(a)/sizeof(a[0]))<<endl;

    return 0;
}

int findmajority(int a[],int n)
{
    int maj_in =0;
    int count =1;
    for(int i=1;i<n;i++)
    {
        if(a[maj_in]==a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count==0)
        {
            count =1;
            maj_in =i;
        }
    }

    //checking if it is a majority element
    count=0;
    for(int i=0;i<n;i++)
    {
        if(a[maj_in]==a[i])
        {
            count++;
        }
    }
    if(count > n/2)
    return a[maj_in];
    return -1;
}