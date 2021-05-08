#include <bits/stdc++.h>
using namespace std;
int problemSolution(int a[],int size,int m);
int solution(int a[],int size,int m, int sum[],int start);


int main()
{
    int a[] = {10 ,10, 10, 10};
    cout<<problemSolution(a,sizeof(a)/sizeof(a[0]),2)<<endl;
    cout<<"Done"<<endl;
    return 0;
}
int solution(int a[],int size,int m,int sum[],int start)
{
    if(m==1)
    return sum[size] - sum[start];

    int ans = INT_MAX;
    for(int i=start;i<size - m ;i++)
    {
        int x = solution(a,size,m-1,sum,i+1);
        int y = sum[i+1]-sum[start];
        cout<<x<<" and  "<<y<<endl;
        ans = min(ans,max(x,y));
    }
    return ans;   
}

int problemSolution(int a[],int size,int m)
{
    int sum[size+1];
    sum[0]=0;
    //precalculated  sum array
    for(int i=1;i<=size;i++)
    {
        sum[i] = sum[i-1]+a[i-1];
    }
    return solution(a,size,m,sum,0);
}