#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main(){
    int a []= {2,5,1,1,3,7,4,6};
    multiset <int> s;
     for(int i=0;i<8;i++){
         s.insert(a[i]);
     }

     int count = 0;
     auto i = s.begin();
for(;i!=s.end()&&count<4;i++){
    cout<<*i<<" ";
    count++;
}
    i--;
    cout<<*i<<endl;
    return 0;
}