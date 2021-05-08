#include <bits/stdc++.h>
using namespace std;
string minimumLengthWindoToContainItself(string s);


int main()
{
    cout << minimumLengthWindoToContainItself("aabcbcdbca") << endl;
    return 0;
}

string minimumLengthWindoToContainItself(string s)
{
    unordered_set<char> us;
    int size = s.size();
    for(int i=0;i<size;i++)
    {
        us.insert(s[i]);
    }

    int dis_count = us.size();

    int start = 0;
    string minPart = "";
    int min_length = INT_MAX;
    int count= 0 ;
    int hash[256] = {0}; //fill it with zeros
    for(int i=0;i<size;i++)
    {
        if(++hash[(int)s[i]]==1) //increase count
            count++;
        if(count == dis_count)
        {
            while(hash[(int)s[start]]>1)
            {   hash[(int)s[start]]--;
                start++;
            }

            if(min_length>i-start+1)
            {
                min_length = i-start+1;
                minPart = s.substr(start,min_length);
                // cout<<minPart<<endl;
            }
        }
    }
    return minPart;
}












