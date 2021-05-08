#include <bits/stdc++.h>
using namespace std;
int rowWithMaxOne(int [][4],int r,int c);


int main(){
    int mat[4][4] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0} };
    cout<<rowWithMaxOne(mat,4,4);

     return 0;
}

int rowWithMaxOne(int a[][4],int r,int c){
    int pointer;
    int j = c-1;
    for(int i=0;i<r;i++){

        while(j>=0&&a[i][j]==1){
        j--;
        pointer = i;
        }
    }

    return pointer;
}