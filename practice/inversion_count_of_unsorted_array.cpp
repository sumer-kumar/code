#include <bits/stdc++.h>
using namespace std;
#define int long long int

int merge(int a[],int temp[],int start,int mid,int end)
{
    int i = start;//pointer to part one
    int j = mid; //pointer to part two
    int k = start ; //pointer to temp array
    int count=0;
    while(i<mid&&j<end)
    {
        if(a[i]<a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count+=(mid-i);
        }
    }
    while(i<mid)
    temp[k++]=a[i++];

    while(j<end)
    temp[k++]=a[j++];

    for(i=0;i<end;i++)
    {
        a[i]=temp[i];
    }
    return count;
}


int merge_sort(int a[],int temp[],int start,int end)
{
    int count = 0;
    if(start<end)
    {
        int mid = start + (end - start)/2;
        count+=merge_sort(a,temp,start,mid);
        count+=merge_sort(a,temp,mid+1,end);
        count+=merge(a,temp,start,mid+1,end);
    }
    return count;
}

int inversion_count(int a[],int size)
{
    int temp[size];
    return merge_sort(a,temp,0,size);
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {2, 4, 1, 3, 5};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<inversion_count(a,size)<<endl;
    return 0;
}