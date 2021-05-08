#include <bits/stdc++.h>
using namespace std;
int a[100001]={0};
int minDistance(int n,int c);
bool isValid(int mid,int n,int c);

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,c;
        cin>>n>>c;
        for(int i=0;i<n;i++)
        cin>>a[i];

        cout<<minDistance(n,c)<<endl;
    }

    return 0;
}

int minDistance(int n,int c)//c for number of cows
{
    sort(a,a+n);
    int start = a[0];
    int end = a[n - 1] - a[0];
    int ans = 0;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isValid(mid,n,c))
        {
            start = mid+1;
            ans = max(ans,mid);
        }
        else
        {
            end = mid -1;
        }
    }
    return ans;
}
//is valid commpleted
bool isValid(int mid,int n,int c)
{   int count = 1;
    int pre = 0;
    for(int i=1;i<n;i++)
    {
        if(a[i] - a[pre]>=mid)
        {
            count++;
            pre=i;
        }    
    }
    return count>=c?true : false;
}