#include <bits/stdc++.h>
using namespace std;
bool isWildcar(string wild,string original);


int main()
{
    cout<<"Is Wild"<<endl;
    string wild = "a***a";
    string original = "aa";
    cout<<original<<"--->"<<wild<<"-->"<<endl;
    cout<<isWildcar(wild, original);
    
     return 0;
}

bool isWildcar(string wild,string original)
{
    int sizew = wild.size();
    int sizeo = original.size();

    bool dp[sizeo+1][sizew+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;

    //to replace initial empty characters with *
    for(int i=1;i<=sizew;i++)
    {
        if(wild[i-1]=='*')
        {
            dp[0][i] = dp[0][i-1];
        }
    }

    //for filling the 2 d matix
    for(int i=1;i<=sizeo;i++)
    {
        for(int j=1;j<=sizew;j++)
        {   //if it is*
            //then there are two cases
            //either we can take it as empty 
            //or we can take it as a character
            if(wild[j-1]=='*')
            {
                dp[i][j] = dp[i-1][j]||dp[i][j-1];
            }

            else if (wild[j-1]==original[i-1] || wild[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[sizeo][sizew];
}










