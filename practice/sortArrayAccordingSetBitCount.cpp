#include <bits/stdc++.h>
using namespace std;

int countSetBit(int n);
bool cmp(int a,int b);
void sortSetBit(int a[],int size);

int main()
{
    int a[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    sortSetBit(a,sizeof(a)/sizeof(a[0]));
    return 0;
}

unordered_map<int,int> um;
void sortSetBit(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        um[a[i]] = countSetBit(a[i]);
    }

    stable_sort(a,a+size,cmp);

    // for(auto x: a)
    // cout<<x<<" ";
    for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
    um.clear();
}
bool cmp(int a,int b)
{
    return um[a]>um[b]; 
}

int countSetBit(int n)
{
    int umBit = 0;
    while(n)
    {
        umBit++;
        n&=(n-1);
    }
    return umBit;
}