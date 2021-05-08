#include <bits/stdc++.h>
using namespace std;


#define max 10000001

long long chocolate(long long a[],long long n,long long m);
int main(){
    long long *a = new long long [max];
    long long test;
    cin>>test;
    while(test--){
        long long size;
        cin>>size;
        for(long long i=0;i<size;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        cout<<chocolate(a,size,m)<<endl;
    }

   // cout<<"what"<<endl;


    return 0;
}

long long chocolate(long long a[],long long n,long long m){
    long long minDiff = LONG_LONG_MAX;

    sort(a,a+n);

    int i=0;
    int j = i+m-1;

    for( ;j<n;j++,i++){
        minDiff = min(minDiff,a[j]-a[i]);
    }
    return minDiff;
}