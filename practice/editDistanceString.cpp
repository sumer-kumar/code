#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1,string s2);


int main()
{
    cout<<editDistance("sunday","saturday")<<endl;

    return 0;
}
//hey i like to add comments so dont take it so seriously
//just google if you dont understand
//:p
//check if its working
int editDistance(string s1,string s2)
{
    int size1=s1.size(),size2=s2.size();

    //creating a 2d matrix bang!!!!!
    int dp[size1 + 1][size2 + 1];

    for(int i=0;i<=size1;i++)
    {
        for(int j=0;j<=size2;j++)
        {
            if(i==0)
            dp[i][j]=j;

            else if(j==0)
            dp[i][j]=i;

            else if(s1[i]==s2[j])
            dp[i][j]=dp[i-1][j-1];

            else 
            dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i][j-1]));

        }
    }

    return dp[size1][size2]; //to return
}