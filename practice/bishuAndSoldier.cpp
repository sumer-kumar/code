#include <bits/stdc++.h>
using namespace std;
vector<int> a (20000,0);
void bishuProblem(int,int);
int main()
{
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    cin>>a[i];
    int test;
    cin>>test;
    while(test--)
    {   int bishuPower;
       cin>>bishuPower;
        bishuProblem(size,bishuPower);
    }
    return 0;
}

void bishuProblem(int size,int bishuPower)
{
    sort(a.begin(),a.begin()+size);
    vector<int> :: iterator tp= upper_bound(a.begin(),a.begin()+size,bishuPower);
    int upper = tp - a.begin();
    int sums=0;
    for(int i=0;i<upper;i++)
    sums+=a[i];
    cout<<upper<<" "<<sums<<endl;
}