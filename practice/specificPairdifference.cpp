#include <bits/stdc++.h>
using namespace std;

void differencePair(int [],int,int);

int main()
{
    int a[] = {1,8,30,40,100};
    differencePair(a,sizeof(a)/sizeof(a[0]),60);
    return 0;
}

void differencePair(int a[],int size,int x)
{
    sort(a,a+size);
    bool findOne = false;
    for(int i=0,j=1;i<size&&j<size;)
    {
        if(a[j]-a[i]==x)
        {   findOne = true;
            cout<<"["<<a[i]<<","<<a[j]<<"]";
            i++;
            j++;
        }
        else
        {
            if(a[j]-a[i]>x)
            i++;
            else
            j++;
        }
    }
    if(!findOne)
    cout<<"Not found"<<endl;
}