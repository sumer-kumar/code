
#include <iostream>
#include <climits>

using namespace std;

int maxSubArraySum(int a[],int n){
    int *sum = new int[n]; //to store continuos sum of array from index 0 to n
    sum[0]=a[0]; //first element will be same as

    int minIndex = 0;
    int maxIndex = 0; 

    for(int i=1;i<n;i++)
        

        return maxSum;


}   




int main(){
    int a[] = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75}; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout<<maxSubArraySum(a, n);


    return 0;
}