#include <iostream>
#include <iterator>
#include <set>

using namespace std;
//using stl
long long int countInversion(long long a[], long long n)
{
    multiset<long long> m ;
    multiset<long long> :: iterator it;
    long long count = 0;
    
    for(long long i=0;i<n;i++){
        count+=distance(m.insert(a[i]),m.end());
    }
    return count-n;
}
//main
int main(){
    long long a[] = {2, 3, 4, 5, 6};
    cout<<countInversion(a,sizeof(a)/sizeof(a[0]))<<endl;
    return 0;
}