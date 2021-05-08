#include <bits/stdc++.h>
using namespace std;


int trapping(int a[],int n);

int main(){
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trapping(a,sizeof(a)/sizeof(a[0]));

    return 0;
    
}

int trapping(int a[],int n){
    int water =0; //to sum the water at every instances 

    int left[n]; //trace the max from left side
    int right[n]; //trace the max from right side

    left[0] = a[0];
    for(int i=1;i<n;i++)
    left[i] = max(left[i-1],a[i]);

    right[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],a[i]);
    }

    //to calculate the trapped water
    for(int i=0;i<n;i++)
    water+=min(left[i],right[i])-a[i];

    return water;
}