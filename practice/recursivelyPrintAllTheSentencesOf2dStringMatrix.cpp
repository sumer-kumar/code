#include <bits/stdc++.h>
using namespace std;
void sentences(vector<vector<string>> &a, int = 0, string = "");



int main()
{
    vector<vector<string>> a = {{"you", "we"},
                                {"have", "are"},
                                {"sleep", "eat", "drink"}};
    sentences(a,0);
    return 0;
}

void sentences(vector<vector<string>> &a, int i, string output)
{
    if(i == a.size())
    {
        cout<<output<<endl;
        return;
    }

    for(int j=0;j<a[i].size();j++)
    {
        sentences(a,i+1,output+" "+a[i][j]);
    }

}