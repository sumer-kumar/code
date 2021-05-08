#include <bits/stdc++.h>
using namespace std;
bool checkPresence(string s,vector <string> dict);
bool wordBreak(string s,vector <string> dict);

int main()
{
    
    vector<string> dict = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};

    cout << wordBreak("ilikesamsung", dict) << endl;

    return 0;
}

bool wordBreak(string s,vector <string> dict)
{
    int size = s.size();
    if(size == 0)//if string is empty
        return true;
    
    bool dp[size+1]={0};
    dp[0] = true;

    for(int i=1;i<=size;i++)//traversing through all the characters and
    {//checking if there is string can be formed from the 0 to ith index substring which is present in the dictionary

        if(dp[i]==false&&checkPresence(s.substr(0,i),dict))
        dp[i] = true;

        if(dp[i]==true)
        {
            if (dp[i] == true && i == size)
                return true;

            for(int j = i+1;j<=size;j++)
            {
                if(dp[j]==false&&checkPresence(s.substr(i,j-i),dict))
                dp[j]=true;

                if(j==size&&dp[j]==true)
                return true;
            }
        }
    }
    return false;
}
//utility function
bool checkPresence(string s,vector <string> &dict)
{
    int size = dict.size();
    for(int i=0;i<size;i++)
    {
        if (s.compare(dict[i]) == 0)
            return true;
    }
    return false;
}

