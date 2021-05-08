#include <bits/stdc++.h>
using namespace std;
int a[] = {7, 9, 9, 10, 11, 11, 13, 14, 17, 19};
int b[] = {1, 1 ,4 ,5, 8, 11, 13 ,16 ,19, 19};

void mergeARRAYS(int sizea,int sizeb);


int main()
{   cout<<"start\n";
    mergeARRAYS(10,10);
    
    return 0;   
}
void mergeARRAYS(int sizea,int sizeb)
{
    int size = sizea+sizeb;
    int gap = (size+1)/2;

    while(gap>0)
    {
        int start = 0;
        int end = start+gap;

        while(end<size)
        {
            if(start<sizea)
            {
                if(end<sizea)
                {
                    if(a[start]>a[end])
                    swap(a[start],a[end]);
                }
                else
                {
                    if(a[start]>b[end-sizea])
                    swap(a[start],b[end-sizea]);
                }
            }
            else
            {   
                if(b[start-sizea]>b[end-sizea])
                swap(b[start-sizea],b[end-sizea]);
            }
            start++;
            end++;
        }
        if(gap==1)
        break;
        gap=(gap+1)/2;
    }
}