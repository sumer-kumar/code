#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

vector<long long int> productPuzzel(int a[],int size)
{
    vector<long long int> vec (size,0);
    int count = 0;//number of zeros countt

    for(int i=0;i<size;i++)
    if(a[i]==0)
    count++;

    if(count >=2) //if there are more than one zero
    return vec;

    long long int product = 1; //product without zero
    for(int i=0;i<size;i++)
    if(a[i]!=0)
    product*= (long long int )1*a[i];

    //if there is one zero
    if(count==1)
    for(int i=0;i<size;i++)
    {
        if(a[i]==0)
        vec[i] = product;
    }
    else
    for(int i=0;i<size;i++)
        vec[i] = (long long int)1*product/a[i];

    return vec;
}