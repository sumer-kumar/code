#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v ={1,2,3,4,5};
    for(auto x : v)
    cout<<x<<" ";

    vector<int> v2 = v;

    v2[2] =111;
    cout<<endl;

    for (auto x : v2)
        cout << x << " ";

    int a[] = {1,2,3,4,5,6};
    vector<int> v1 =a; //not possible



    return 0;
}

