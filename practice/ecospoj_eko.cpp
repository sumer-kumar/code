#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ecoeco(int a[],int size,int m);
int binarySearch(int a[],int size,int x);
int32_t main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<ecoeco(a,n,m)<<endl;
    return 0;
}

int ecoeco(int a[],int size,int m)
{
    sort(a,a+size);
    int sums[size+1];
    int mid = 0;
    sums[0]= 0; //first element as zero
    for(int i=1;i<=size;i++)
    {
        sums[i] = sums[i-1]+a[i-1];
    }
    int start = a[0];
    int end = a[size - 1];
    int ans;
    while(start<=end)
    {
        mid = start + (end -start)/2;
        int upper = binarySearch(a,size,mid);
        int diff = sums[size] -sums[upper];

        if(m < diff- mid*(size - upper ))
        {
            start = mid + 1;
            ans = mid;
        }
        else if(m > diff - mid*(size - upper ))
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    
    return ans;
}

int binarySearch(int a[],int size,int x)
{
    int start = 0;
    int end = size-1;
    int mid = 0;
    while(start<=end)
    {
        mid = start + (end - start)/2;
        if(a[mid]<x)
        {
            start = mid+1;
        }
        else
        {
            end = end - 1;
        }
    }
    return mid;
}




