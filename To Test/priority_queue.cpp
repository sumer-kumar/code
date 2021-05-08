#include <bits/stdc++.h>
using namespace std;
 class cmp{
     public:
     bool operator>(const int &a,const int &b){
         return a>b;
     }
 };



int main(){
    cmp c;
    priority_queue<int,vector<int>,cmp> pq;

    for(int j=10;j>0;j--)
    pq.push(j);

    while(!pq.empty()) 
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}