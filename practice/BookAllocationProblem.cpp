#include <bits/stdc++.h>
using namespace std;

bool isValid(int sum[],int mid,int size,int m);

int minimumOfMaximum(int a[],int size,int m);


int main()
{   int a[] = {15,16,32};
    cout<<minimumOfMaximum(a,sizeof(a)/sizeof(a[0]),2);
    
    return 0;
}

int minimumOfMaximum(int a[],int size,int m)
{
    // int sum[size+1] = {0};
    // sum[0] = 0;
    // int maxElement = INT_MIN;
    //we will create a sum array
    // for(int i=1;i<=size;i++)
    // {   maxElement = max(maxElement,a[i-1]);
    //     sum[i] = sum[i-1]+a[i-1];
    // }
    int sum = 0;
    for(int i=0;i<size;i++) 
    sum+=a[i];
    
    int start = 0;
    int end = sum; //final sum;
    int res = INT_MAX;
    while(start<=end)
    {
        int mid = (start+end)/2;
        // cout<<start<<" "<<end<<" "<<mid<<endl;
        if(isValid(a,mid,size,m))
        {
            end = mid - 1;
            res = min(res,mid);
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}   
bool isValid(int a[],int mid,int size,int m)
{
    int curr_sum = 0;
    int count=1;
    for(int i=0;i<size;i++)
    {
        if(a[i]>mid)
        return false;

        if(curr_sum+a[i]>mid)
        {
            count++;
            curr_sum = a[i];
            if(count>m) return false;
        }
        else
        {
            curr_sum+=a[i];
        }       
    }
    return true;
}