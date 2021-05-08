#include <bits/stdc++.h>
using namespace std;

int longestCommanSubsequence(string s1,string s2);


int main()
{
    cout<<longestCommanSubsequence("abcd","bd")<<endl;
    return 0;
}
//its working fine well done lad
int longestCommanSubsequence(string s1,string s2)
{
    int size1=s1.length();//size of 
    int size2=s2.length();

    int lcs[size1+1][size2+1]; //matrix
    //size is taken one because first row and first column should be filled with zero only
    for(int i=0;i<=size1;i++)
    {
        for(int j=0;j<=size2;j++)
        {
            if(i==0||j==0)
            {
                lcs[i][j]=0;
                // continue;
            }

            else if(s1[i-1]==s2[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }

            else
            {
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
    }
    return lcs[size1][size2];
}