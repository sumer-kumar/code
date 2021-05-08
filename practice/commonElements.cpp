#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

// int size(int x[]){
//     int s = sizeof(x) / sizeof(x[0])
//      return s;

// }

vector<int> commanelements(int a[],int n1,int b[],int n2,int c[],int n3){
    vector<int> ab;
    int i,j;
    i=j=0;
    while(i<n1&&j<n2){
        if(a[i]<b[j])
         i++;
        else if(a[i]>b[j])
        j++;

        else
        {
            if (initialize == false || ab.back() != a[i])
            {
                ab.push_back(a[i]);
                initialize = true;
            }
        }
    }

    vector<int> abc ;
    int abSize = ab.size();

    i=j=0;

    while(i<abSize&&j<n3){

        if(ab[i]<c[j])
        i++;
        else if(ab[i]>c[j])
        j++;

        else
        {
            abc.push_back(ab[i]);
            i++;
            j++;
        }
    }

    return abc;
}

int main(){
    int a[]={1, 5, 10, 20, 40, 80};
    int b[]={6, 7, 20, 80, 100};
    int c[]={3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> merged = commanelements(a,6,b,5,c,8);

    for(auto x : merged)
    cout<<x<<" ";
    return 0;
}


