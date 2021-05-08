#include <bits/stdc++.h>
using namespace std;
#define ll long long

void nonRepeatingElement(int a[],int size);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int size = sizeof(a)/sizeof(a[0]);
    nonRepeatingElement(a,size);

    
    return 0;
}

void nonRepeatingElement(int a[],int size)
{
    int xori;
    xori = a[0];
    for(int i=1;i<size;i++)
    {
        xori = xori^a[i];
    }

    int rightSet = xori&~(xori-1);
    
    int xor1=-1;
    int xor2=-1;

    for(int i=0;i<size;i++)
    {
        if(rightSet & a[i])
        {
            if(xor1==-1)
            {
                xor1=a[i];
            }
            else
            {
                xor1=xor1^a[i];
            }
        }
        else
        {
            if(xor2==-1)
            {
                xor2=a[i];
            }
            else
            {
                xor2=xor2^a[i];
            }
        }
    }
    cout<<xor1<<" "<<xor2<<endl;

}