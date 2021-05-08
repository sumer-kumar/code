#include <bits/stdc++.h>
using namespace std;
int searchPAT(string s,int index,string a[],int n,int i,int j);
int countString(string s, string a[],int n);

int main()
{
    string a[] = {"BBABBM",
                  "CBMBBA",
                  "IBABBG",
                  "GOZBBI",
                  "ABBBBC",
                  "MCIGAM"};

    cout<<countString("MAGIC",a,6)<<endl;
    return 0;
}

int countString(string s, string a[],int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(s[0]==a[i][j])
            count+=searchPAT(s,0,a,n,i,j);//(string,index,array,size of array,i,j)
        }
    }
    return count;
}


int searchPAT(string s,int index,string a[],int n,int i,int j)
{   
    int count=0;

    if(index + 1== s.size())
    return 1;

    if(i-1>=0&&a[i-1][j]==s[index+1])
        count+=searchPAT(s,index+1,a,n,i-1,j);

    if (i + 1 < n && a[i + 1][j] == s[index + 1])
        count += searchPAT(s,index+1,a,n,i+1,j);

    if(j+1<a[i].size()&&a[i][j+1]==s[index+1])
        count+= searchPAT(s,index+1,a,n,i,j+1);

    if(j-1>=0&&a[i][j-1]==s[index+1])
        count+= searchPAT(s,index+1,a,n,i,j-1);

    return count;
}