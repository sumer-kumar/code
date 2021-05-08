#include <bits/stdc++.h>
using namespace std;
int subarraySumZero(int [],int);
int main()
{
    int a[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<subarraySumZero(a,size);
    return 0;
}

int subarraySumZero(int a[],int size)
{
    int count = 0;
    unordered_map<int,int> um;
    um[0]++;
    int sum = 0;

    for(int i=0;i<size;i++)
    {
        sum+=a[i];
        count+=um[sum]++;
    }
    for(auto i = um.begin();i!=um.end();i++)
    cout<<i->first<<"--->"<<i->second<<endl;

    return count;
}