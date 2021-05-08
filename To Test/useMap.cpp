#include <iostream>
#include <map>



using namespace std;

int main(){
    multimap<int,int> m ;
    pair<int,int> q ;
    for(int i=0;i<10;i++)
    {
        q.first = i;
        q.second = i+3;

        m.insert(q);
    }

    for(auto it = m.begin();it!=m.end();it++)
    {cout<<it->first<<"  "<<it->second;
    
    cout<<endl;}
    return 0;
}