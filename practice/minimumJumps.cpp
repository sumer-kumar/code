#include <iostream>
#include <cstdlib>

using namespace std;

int minjumps(int a[], int size); 

int main()
{
    int a[] = {0, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;
    cout<<minjumps(a,n);
}

int minjumps(int a[],int size){
    if(size == 0||a[0]==0) return -1;

    int *jump = new int[size+1];
    jump[0] = 0;
    for(int i=1;i<size;i++){
        jump[i]=-1;
    }

    for(int i=1;i<size;i++){
        
        for(int j=0;j<i;j++){
            if(j+a[j]>=i){  //when iindex i is reachable from j
                if(jump[i]==-1)
                    {
                        jump[i] = jump[j]+1;
                    }
                else
                {
                    jump[i] = min(jump[j]+1,jump[i]);
                }
                break;
            }
        }
    }

    return jump[size-1];

}