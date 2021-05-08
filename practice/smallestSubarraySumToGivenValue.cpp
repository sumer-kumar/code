#include <bits/stdc++.h>
using namespace std;
int smallestSubWithSum(int [],int ,int);
int main(){
    int a[] = {1, 4, 45, 6, 10, 19};
    cout<<smallestSubWithSum(a,sizeof(a)/sizeof(a[0]),51)<<endl;
    return 0;
}

int smallestSubWithSum(int a[],int n,int x){
    int min = n;
    int currSum = 0;
    int start =0;
    int end =0;
    while(end<n)
    {
        while(currSum<=x&&end<n)
        {
            currSum+=a[end++];
        }

        while(currSum>x&&start<n)
        {
            if(end-start<min)
                 min = end-start;

            currSum-=a[start++];
        }
    
    }
    return min;
}