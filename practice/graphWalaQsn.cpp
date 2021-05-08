#include <bits/stdc++.h>
using namespace std;

int qsn(int a[],int size);

void addEdge(vector<int> a[],int v2,int v1);


int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int P = qsn(a,n);
    if(P-k>0)
    cout<<"Yes\n"<<(P-k)<<endl;
    else
    {
        cout<<"No\n"<<(P-k)<<endl;
    }
    

    return 0;
}

int qsn(int a[],int size)
{
    int v1,v2;
    vector<int> v[size];
    for(int i=0;i<size-1;i++)
    {
        cin>>v1>>v2;
        addEdge(v,v1,v2);
    }
    // int maxP = INT_MIN;
    // int currMax = INT_MIN;
    int maxSum = 0;
    for(int i=0;i<size;i++)
    {
        int currSum = 0;
        for(int j=0;j<v[i].size();j++)
        {
            currSum+=a[v[i].at(j)];
            // cout<<(a[v[i].at(j)]+a[i])<<" ";
        }
        maxSum = max(maxSum,currSum+a[i]);
        // cout<<maxSum<<endl;
        currSum = 0;
    }
    return maxSum;
}

void addEdge(vector<int> v[],int v2,int v1)
{
    v[v1-1].push_back(v2-1);
    v[v2-1].push_back(v1-1);
}