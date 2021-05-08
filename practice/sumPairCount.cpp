#include <bits/stdc++.h>
using namespace std;
int countPair(int a[],int n, int k);
int main(){
    int a[] = { 1, 5, 7, -1, 5 };
    cout<<countPair(a,sizeof(a)/sizeof(a[0]),6);

    return 0;

}

int countPair(int a[],int n, int k){
    unordered_map <int,int> um;
    int count =0; //each each pair will be counted twice
    for(int i=0;i<n;i++){
        um[a[i]]++; //to map/hash the  number with its frequency
    }
    for(int i=0;i<n;i++){
    count+=um[k-a[i]];

    if(k-a[i]==a[i])
    count--;
    }

    

    return count/2;
}