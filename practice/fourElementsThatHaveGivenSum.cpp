#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourWaySum(vector<int> &a, int x) ;


int main()
{
    vector<int> a = {1, 4, 45, 6, 10, 12};
                    //1  4  6  10  12  45
    int sum =21;
    vector<vector<int>> vec = fourWaySum(a,sum);
    // cout<<vec.size()<<endl;

    for(auto x : vec)
    {   cout<<"[";
        for(auto p : x)
        cout<<p<<",";
        cout<<"\b]\n";
    }


    return 0;
}

vector<vector<int>> fourWaySum(vector<int> &a,int x)
{
    vector<vector<int>> res;
    //1  4  6  10  12  45
    if(a.size()<3)
    return res;
    vector<int> holder(4,0);
    sort(a.begin(),a.end()); //sorting array

    for(int i=0;i<a.size()-3;i++) //for loop 1
    {
        for(int j=i+1;j<a.size()-2;j++) //for loop 2
        {
            int req = x - a[i] -a[j];
            for(int start = j+1,end = a.size()-1;start<end;)//for loop
            {
                if(a[start]+a[end]==req)
                {
                    holder[0] = a[i];
                    holder[1] = a[j];
                    holder[2] = a[start];
                    holder[3] = a[end];
                    start++;
                    end--;
                    res.push_back(holder);
                    // cout<<"$";
                }
                else if (a[start] + a[end] < req)
                {
                    start++;
                }
                else //sum is greater condition 
                {
                    end--;
                }
            }//end of for loop 3
        }//end of for loop 2
    }//end of for loop 1


    return res;
}