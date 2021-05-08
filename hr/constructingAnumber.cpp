#include <bits/stdc++.h>
using namespace std;

int digitSum(int n);
string constructAnumber(int a[],int size);


int main()
{
    int a[] = {4,1};
    cout<<constructAnumber(a,2)<<endl;
    return 0;
}

string constructAnumber(int a[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=digitSum(a[i]);
    }
    return sum%3==0?"Yes":"No";
}

int digitSum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum = n%10;
        n/=10;
    }
    return sum;
}