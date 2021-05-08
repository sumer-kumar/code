#include <bits/stdc++.h>

using namespace std;
#define max 10

void rotateClock90(int a[][max],int r,int c);
void displayMat(int a[][max],int c,int r);

int main(){
    int a[3][max] = {{1,2,3,4,5},
                   {6,7,8,9,1},
                   {2,3,4,5,6}};

    displayMat(a,5,3);
    cout<<endl;
    rotateClock90(a,3,5);
    return 0;
}

void rotateClock90(int a[][max],int r,int c){

    for(int j=0;j<c;j++){
        for(int i=r-1;i>=0;i--){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}

void displayMat(int a[][max],int c,int r){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}