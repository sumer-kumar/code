#include <iostream>
#include <stdio.h>

using namespace std;

void asidingNegative(int a[],int size){
    int i=0,j=size-1;
  while(i<j){ 
    while(a[j]>0) j--;
    while(a[i]<0) i++;
    swap(a[i],a[j]);

    }
}

int main(){
    int a[]={-1,2,4,-4,-7,7,3,-34,3};
    asidingNegative(a,9);

    
    return 0;
}