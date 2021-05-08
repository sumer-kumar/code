// i just took expample of 2x2 2d matrix


#include <iostream>

using namespace std;

void power(int a[][2],int exp,int n);
void mult(int mat1[][2],int mat2[][2],int I[][2]);


int main(){
    int a[][2] = {{1,1},
                  {1,1}};

    power(a,4,2);

    return 0;
}

void power(int a[][2],int exp,int n){
    int I[][2] = {{1,0},
                  {0,1}};

    while(exp){
        if(exp%2)
        {
            //I = I*a;
            mult(I,a,I);
            exp--;
        }

        else{
            //a = a*a;
            mult(a,a,a);
            exp/=2;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<I[i][j]<<" ";
        cout<<endl;
    }
}

void mult(int mat1[][2],int mat2[][2],int I[][2])
{
    int i, j, k;
    int res[2][2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (k = 0; k < 2; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            I[i][j] = res[i][j];
        }
    }
    
    
}