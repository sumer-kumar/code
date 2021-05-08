#include <bits/stdc++.h>
using namespace std;
void display(unordered_map<int, int> &um) ;
int main()
{   
    unordered_map<int,int> um;
    um[10] = 0;
    cout<<(um[10]==0)<<endl;

    // for(int i =0 ; i<10;i++)
    // {   
    //     um[i] = 10;
    // }
    // display(um);
    // for(int i =0 ; i<10;i++)
    // {
    //     um[i]--;
    // }
    // cout<<"CHaliye dekhiye kya hota hai"<<endl;
    // display(um);
}

void display(unordered_map<int,int>&um){
    unordered_map<int, int> :: iterator i;
     for ( i = um.begin(); i != um.end(); i++)
    {
        cout<<i->first<<"  "<<i->second<<endl;
    }
}