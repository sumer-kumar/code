#include <bits/stdc++.h>
using namespace std;


bool comp(vector<int>&a,vector<int> &b)
{
    return a[1]<b[1];
}

int binarySearch(vector<vector<int>> &v,int index)
{
    int start = 0;
    int end = index-1;
    int mid ;
    while(start<=end)
    {
        mid = start + (end - start)/2;
        if(v[mid][1] <= v[index][0] )
        {
            if(v[mid+1][1] <= v[index][0])
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int max_profit(vector<int> start,vector<int> end,vector<int> profit)
{
    int size = start.size();
    vector<vector<int>> v(size);
    
    for(int i=0;i<size;i++)
    {
        v[i] = {start[i],end[i],profit[i]};
    }
    //sorting 
    sort(v.begin(),v.end(),comp);

    int dp[size]={0};
    dp[0] = v[0][2]; //assigning profit of 0th index
    for(int i=1;i<size;i++)
    {
        int ind = binarySearch(v,i);
        int curr_profit = v[i][2];
        if(ind != -1)
        {
            curr_profit+=dp[ind];
        }   
        dp[i] = max(dp[i-1],curr_profit);
    }
    return dp[size - 1];
}

int main()
{
    vector<int> start = {1,3,6,2};
    vector<int> end = {2,5,19,100};
    vector<int> profit = {50,20,100,200};
    cout<<max_profit(start,end,profit)<<endl;
    return 0;
}