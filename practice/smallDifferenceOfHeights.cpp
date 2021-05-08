#include <bits/stdc++.h>
using namespace std;


int minimumSum(int a[],int size,int k);
int main(){
    int a[] = {1,5,15,10};
    cout<<minimumSum(a,4,3);


    return 0;
}


int minimumSum(int a[],int size,int k){
    
    
        sort(a,a+size);

        int small = a[0]+k;
        int big = a[size-1]-k;

        int ans = a[size-1]-a[0];
      //if small is bigger than big 
        if(small>big)
            swap(small,big);

        for(int i=1;i<size-1;i++){
            int subtract = a[i]-k;
            int add = a[i]+k;

            //there must be no change when condition
            //subtract is greater than small i.e it will cause no harm
            //and if the add is less than or equal to big
            if(subtract >= small || add <= big)
                continue;

            if(big - subtract <= add - small)
                small = subtract;

            else 
                big = add;

        }

    return min(big-small,ans);
}