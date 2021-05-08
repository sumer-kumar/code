#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

int maxSUM(int a[],int size)
{
    int ex = 0;
    int in = a[0];

    for(int i=0;i<size;i++)
    {
        int temp = ex;
        ex = max(ex,in);
        in = temp+a[i];
    }
    return max(in,ex);

}