#include <bits/stdc++.h>
using namespace std;
void tripletSumAsk(int a[], int n, int k) ;

int main()
{   int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]);
    tripletSumAsk(A,arr_size,sum);
    return 0;
}
void tripletSumAsk(int a[],int n,int k){
    unordered_set <int> us;

    for(int i=0;i<n;i++){
        us.insert(a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(us.find(k-a[i]-a[j])!=us.end()){
                cout << (k - a[i] - a[j])<<","<<a[i]<<","<<a[j]<<endl;
                return ;
            }
        }
    }

    cout<<"nothing"<<endl;
}