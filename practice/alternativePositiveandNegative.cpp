#include <iostream>
using namespace std;

void rearrange(int a[], int n);
void rotate(int a[], int low, int high);

int main()
{
    int a[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(a) / sizeof(a[0]);
    rearrange(a,n);
    for (auto x : a)
        cout << x << " ";

    return 0;
}

void rearrange(int a[],int n){

    

    int i = 0; //to find the odd element
    int j=0; //to find the first replacement of the element at i
    bool evenIndex = true; //to check the if the index is even or odd 
                           //used to avoid everytime taking modulo 
    bool workDone = false;
    while(i<n&&j<n&&!workDone){

        if(a[i]<0 && (i&1) )
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]>0)
                    {
                        //rotate(a,low,high)
                        rotate(a,i,j);
                        break;
                    }
            }
            if(j==n-1)
            workDone = true;
            i++;
            
        }

        else if (a[i] > 0 && !(i&1))
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<0)
                {
                    //rotate(a,low,high)
                    rotate(a, i, j);
                    break;
                }
            }

            if(j==n-1)
            workDone = true;
        }

        else
        {
            i++;
        }
    }

}
void rotate(int a[],int low,int high){
    int last = a[high];

    for(int i=high;i>low;i--){
        a[i] = a[i-1];
    }
    a[low]=last;
}
/**
 * My approach is based on the idea that every positive element must be on the odd place if the index 
 * and negative element must on the even place of the inde
 * ->if the condition is not satisfied then we seach of the element that is suitable of that index 
 * ->and rotate the array to right by one element 
 * ->lets code
 * */