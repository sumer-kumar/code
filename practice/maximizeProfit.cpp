#include <iostream>
#include <cstdlib>

using namespace std;

int maximizeProfit(int a[],int n){

    int minPrice = a[0]; //in starting first element is minimum
    int maxProfit=0;
    int cost =0;

    for(int i=0;i<n-1;i++){
        minPrice = min(minPrice,a[i]);

        cost = a[i] - minPrice;

        maxProfit = max(cost,maxProfit);
    }

    return maxProfit;
}

int main(){
    int a[] = {7, 1, 5, 3, 6, 4};
    cout<<maximizeProfit(a,sizeof(a)/sizeof(a[0]))<<endl;

    return 0;
}