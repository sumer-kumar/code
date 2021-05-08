#include <bits/stdc++.h>
using namespace std;
int pivotIndex(int a[],int size);
int main()
{
    int a[] = {5,6,7,8,9,10};
    cout<<pivotIndex(a,sizeof(a)/sizeof(a[0]));
    return 0;
}
int pivotIndex(int a[],int size)
{
    if(a[0]<a[size-1])
    return -1;

    int start = 0;
    int end = size -1;
    int last = ceil(log2(size));
    int mid;
    for(int i=0;i<last;i++)
    {
        mid = (start+end+1)/2;
        if(a[mid]>a[end])
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }
    return mid;
}