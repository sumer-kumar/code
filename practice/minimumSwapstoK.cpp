#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(int n,int k);
int a[] = {2, 7, 9, 5, 8, 7, 4};
int main()
{
    
    cout<<minimumSwaps(sizeof(a)/sizeof(a[0]),6)<<endl;
    return 0;
}

int minimumSwaps(int n,int k)
{
    int count=0;
    int left=0;
    int right = n-1;

    while(left<right){
        while(a[left]<=k)
        left++;

        while(a[right]>k)
        right--;

        swap(a[left],a[right]);
        count++;

        left++;
        right--;
    }


    return count;
}