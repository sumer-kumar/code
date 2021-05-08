#include <bits/stdc++.h>
using namespace std;

bool check(int mid ,int n )
{   
    // int temp = mid;
    int x = 5;
    // int num;
    int count = 0;
    while(x<=mid)
    {
        count+=mid/x;
        x*=5;
    }
    return (count>=n);
}


int trailingZeros(int n)
{
    if(n == 1)
    return 5;
    int start = 0;
    int end = n*5;
    while(start<end)
    {
        int mid = start + (end - start)/2;
        if(check(mid,n))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    cout<<trailingZeros(8)<<endl;
    return 0;
}