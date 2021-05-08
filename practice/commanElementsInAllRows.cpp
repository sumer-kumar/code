#include <bits/stdc++.h>
using namespace std;


void commanElementsInRow(int a[][5],int n,int m);

int main(){
    int mat[][5] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };
        commanElementsInRow(mat,4,5);
    return 0;
}

void commanElementsInRow(int a[][5],int n,int m){
    unordered_map<int,int> um;  //mapping value and its count

    //inserting first element
    for(int i=0;i<m;i++)
    um[a[0][i]]=1;


    //inserting element if only its current count is equal to its index element
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(um[a[i][j]]==i)
            {
                um[a[i][j]]++; //incrementing count;

                if (i == n - 1)
                {
                    cout << a[i][j] << " ";
                }
            }

        }
    }


    




}