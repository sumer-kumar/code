#include <bits/stdc++.h>

using namespace std;

int consequtive(int a[],int n);


int main(){
    int a[] = {1, 9, 3, 5, 6, 20, 2};
    cout<<consequtive(a,sizeof(a)/sizeof(a[0]));

    return 0;
}


int consequtive(int a[],int n){
    unordered_set<int> s;

    for(int i=0;i<n;i++){ //hashing in the set
        s.insert(a[i]);
    }
    int count = 0;

    for(int i=0;i<n;i++){
        int j=a[i];

        if(s.find(a[i]+1)!=s.end()){
            while(s.find(j)!=s.end())
            j++;
        }
    count = max(j-a[i],count);
    }

    return count;
}