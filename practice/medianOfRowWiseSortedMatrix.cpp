#include <bits/stdc++.h>
using namespace std;
int matrixMedian(int a[][3],int,int);
int maximum(int a,int b){
    return a>b?a:b;
}
int minimum(int a,int b){
    return a<b?a:b;
}


int main(){
    int r = 3, c = 3;
    int a[3][3] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout<<matrixMedian(a,3,3)<<endl;

    return 0;

}

int matrixMedian(int a[][3],int r,int c){
 //   int median;
    int max=a[0][c-1],min=a[0][0];

    for(int i=1;i<c;i++){
        //to find the maximum from the  last column
        max = maximum(a[i-1][c-1],a[i][c-1]);

        //to find the minimum from the first column
        min = minimum(a[i-1][0],a[i][0]);
    }
    
    
    int desired = (r*c+1)/2; //exactly (r*c+1)/2 elements must be smaller than the median
    while(min<max){
        //calculating mid
        int mid = min + (max - min) / 2;
        int place = 0; //no. of elements that are smaller than the upper bound of the median
        //upper bound of some element x is the element which is just greater than the x in the range

        for(int i=0;i<c;i++){ //scanning each row
                              //upper_bound(a[i],a[i]+c,mid) will give the position w.r.t the memory
                              //bt upper_bound(a[i],a[i]+c,mid)-a[i]; will give wrt the a[i].
            place+= upper_bound(a[i],a[i]+c,mid)-a[i];
        }

        if(place<desired) //means there are less n0. of elements than the desired
        min = mid+1;      //so median must on the right side

        else 
        max = mid;
    }

    return min;
}