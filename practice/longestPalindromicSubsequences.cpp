#include <bits/stdc++.h>
using namespace std;
int countPS(string s);

int main()
{
   cout<<countPS("abacd")<<endl;
    return 0;
}

int countPS(string s)
{   
    int size = s.size(); 
    int dp[size+1][size +1];

    memset(dp,0,sizeof(dp)); //filling 2d array with 0s
    //for length one
    for(int i =0;i<size;i++)
    dp[i][i]=1;

    for(int l = 2;l<=size;l++)//l is length if the string   
    {   
        for(int i = 0;i<=size-l;i++)
        {
            int k = l + i -1; //represents the last index of part of the string from i to length of l

            //then there will be two conditions one is when last characters of
            //part of  the strings matches with first character of the part of the string
            //or not
            //so
            if(s[i]==s[k])
            {
                dp[i][k] = dp[i+1][k]+dp[i][k-1]+1;
            }
            else //if not equal 
            {
                dp[i][k] = dp[i+1][k]+dp[i][k-1] - dp[i+1][k-1];
            }
        }
    }
    //un-comment it for printing the 2d array
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[0][size-1];
}
