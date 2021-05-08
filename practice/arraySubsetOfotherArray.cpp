#include <bits/stdc++.h>
using namespace std;

string checkSubset(int a[],int sizea,int b[],int sizeb);

int main(){
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    cout<<checkSubset(arr1,m,arr2,n);
    return 0;
}

string checkSubset(int a[],int sizea,int b[],int sizeb){  //sizeb<=sizea (must condition)
    unordered_set<int> us;
    for(int i=0;i<sizea;i++){
        us.insert(a[i]);
    }

    for(int i=0;i<sizeb;i++){
        us.insert(b[i]);
        if(sizea>us.size())
        return "No";
    }

   return "Yes";
}