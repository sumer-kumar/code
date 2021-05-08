#include <bits/stdc++.h>
using namespace std;
int fun(int n,int m,int k,int mArray[]);

int main()
{
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    int mArray[k];
    for(int i=0;i<k;i++)
    cin>>mArray[i];

    cout<<fun(n,m,k,mArray)<<endl;
    return 0;
}

int fun(int n,int m,int k,int mArray[])
{
    int a[n] = {0};
    for(int i=0;i<m;i++)
    {
        a[mArray[i]-1] = 2;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==2)
        {   int t = i-1;
            int times = k;
            while(t>=0&&a[t]==0&&times--)
            {
                a[t--] = 1;
            }
            t=i+1;
            times = k;
            while(t<n&&a[t]==0&&times--)
            {
                a[t++]=1;
            }
        }
    }
    // for(auto x:a)
    // cout<<x<<" ";

    int count = 0;
    int start = 0;
    int end = 0;
    int req=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            start = i;
            end = i;

            while(a[end++]==0&&end<n)
            count++;
            cout<<count<<endl;
            i+=end-1;
            req+=1+(count-1)/(2*k+1);
            count=0;
        }
    }
    return req;
}