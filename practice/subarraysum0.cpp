#include <bits/stdc++.h>
using namespace std;


bool sumsubarray0(int a[],int n){
    int sum =0;
    unordered_set<int> us;
    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum==0||us.find(sum)!=us.end())
        return true;
        us.insert(sum);
    }
    return false;
}


int main(){
    int a[] = {4,2,-3,1,6};
    cout<<sumsubarray0(a,sizeof(a)/sizeof(a[0]));


    return 0;
}