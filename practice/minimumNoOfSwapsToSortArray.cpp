#include <bits/stdc++.h>
using namespace std;
int minimumSwaps(int [],int);

int main()
{
    int a[] = {101, 758, 315,
               730, 472, 619,
               460, 479};
    cout<<minimumSwaps(a,sizeof(a)/sizeof(a[0]))<<endl;

    return 0;
}

int minimumSwaps(int a[],int size)
{
    vector<pair<int,int>> vep(size,{0,0});  //first is number and second is index
    for(int i=0;i<size;i++)
    {
        vep[i].first = a[i];
        vep[i].second = i;
    }

    sort(vep.begin(),vep.end()); //sorting
    int count = 0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==vep[i].first)
        continue;
        swap(vep[i],vep[vep[i].second]);
        i--;
        count++;
    }
    for(pair<int,int> x : vep)
    cout<<x.first<<" ";
    return count;
}