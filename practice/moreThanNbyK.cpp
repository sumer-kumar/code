#include <bits/stdc++.h>
using namespace std;

void moreThanNdk(int a[], int n,int k);

int main(){
    int a[] = { 4, 5, 6, 7, 8, 4, 4 };

    moreThanNdk(a,sizeof(a)/sizeof(a[0]),4);

    return 0;
}

void moreThanNdk(int a[], int n,int k){
    k = n/k;

    unordered_map<int,int> um;
    /**
     * Key value is for the number 
     * and mapped value is for its count
     * */
    for(int i=0;i<n;i++){
        um[a[i]]++;
    }
    int count;

    for(auto x : um){
        if(x.second>k){
            cout<<x.first<<endl;
        }
    }

}
