#include <bits/stdc++.h>
using namespace std;

int maxProfit2sales(int a[],int n);

int main(){
    int a[] = {2, 30, 15, 10, 8, 25, 80};
    cout<<maxProfit2sales(a,sizeof(a)/sizeof(a[0]));

    return 0;
}

int maxProfit2sales(int a[],int n){
    int profit[n];
    memset(profit,0,sizeof(profit)); //to set all the values to 0 of array

    int minPrice = a[0];
    int maxPrice = a[n-1];

    for(int i = n-2;i>=0;i--){  //should be careful with increment or decrement symbols
        if(a[i]>maxPrice)
        maxPrice = a[i];

        profit[i] = max(profit[i+1],maxPrice-a[i]);
    }

    for(int i=1;i<n;i++){
        if(a[i]<minPrice)
        minPrice = a[i];

        profit[i] = max(profit[i-1],profit[i]+a[i]-minPrice);
    }


    return profit[n-1];
}