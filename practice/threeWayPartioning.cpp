#include <bits/stdc++.h>

using namespace std;

void threeWayPartitioning(int a[],int n,int low,int high);


int main(){
    int a[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    threeWayPartitioning(a,sizeof(a)/sizeof(a[0]),10,20);

    return 0;
}

void threeWayPartitioning(int a[],int n,int low,int high){
    int start =0;
    int end = n-1;
    int i=0;

    while(i<=end)
    {
        if(a[i]<low)
            swap(a[i++],a[start++]);

        else if(a[i]>high)
            swap(a[i],a[end--]);
        
        else
            i++;
    }
}
