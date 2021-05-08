#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int a[],int b[],int sizea,int sizeb,int k);


int main()
{
    int a[] = {1,3,5,7};
    int b[] = {2,4,6,8,10};
    cout<<kthSmallest(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]),8)<<endl;
    return 0;
}

int kthSmallest(int a[],int b[],int sizea,int sizeb,int x)
{
   int res[sizea+sizeb] = {0};
   int i,j,k;
   for(i=0,j=0,k=0;i<sizea&&j<sizeb;k++)
   {
       if(a[i]<b[j])
       {
           res[k]=a[i++];
       }
       else
       {
           res[k] = b[j++];
       }

   }
    while(i<sizea)
    {
        res[k++] = a[i++];
    }
    while(j<sizeb)
    {
        res[k++] = b[j++];
    }
    // for(auto p : res)
    // cout<<p<<" ";
   return res[x-1];
}