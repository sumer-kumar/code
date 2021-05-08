#include <bits/stdc++.h>
using namespace std;
vector<int> firstLast (int [],int,int);
int main()
{
    int a[] = {1,2,3,3,3,3,5,5,6,7,8};
    int x=3;
    int n = sizeof(a)/sizeof(a[0]);
    // vector<int>p= firstLast(a,n,x);
    for (auto t : firstLast(a, n, x))//experiment
        cout << t << " ";

}

vector<int> firstLast(int a[],int n,int x)
{
    bool firstFound = false;
    vector<int> occurence(2, -1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            if (firstFound)
            {
                occurence[1] = i;
            }
            else
            {
                firstFound = true;
                occurence[0] = i;
                occurence[1] = i;
            }
            if(a[i]>x)
            return occurence;
        }
    }
    return occurence;
}