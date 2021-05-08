#include <iostream>
#include <climits>

using namespace std;
void swap(int &a,int &b){
    int t =a;
    a=b;
    b=t;
}

int partition(int a[],int low, int high){
    int pivot = a[high];
    int current = low;
    
    //to find the sorted position for a[high] in array
    for(int i=low;i<high;i++){
        if(a[i]<=pivot){
            swap(a[current],a[i]);
            current++;
        }
    }
    swap(a[current],a[high]);

    return --current;
}

int randomPartition(int a[],int low ,int high){
    int segmentSize = high-low+1; //+1 because for example when random divided by 3 gives remainder 0,1,2; 
    int pivot = rand()%segmentSize;

    swap(a[pivot+low],a[high]);

    return partition(a,low,high);
}

int kthSmallest(int a[],int low,int high,int k){
    if(k > 0 && k <= high - low + 1){
        int pivot = randomPartition(a,low,high);
    //if kth smallest element found
        if(pivot==k-1)
        return a[pivot];

    //when pivot is less than the pivot
    //then kth element will be on right position
    if(pivot<k-1)
    return kthSmallest(a,pivot+1,high,k-pivot-1+low);


    return kthSmallest(a,low,pivot-1,k);


    }
    return INT_MAX;

}



int main(){
    int a[] = {7, 10, 2, 1, 20, 15};

    cout<<kthSmallest(a,0,5,2);

    return 0;
}









