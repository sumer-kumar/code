#include <iostream>
using namespace std;

int main(){
    int number,i,j;
    int pi,pj;
    for( i=1;i<=5;i++){
        for( j=1;j<=5;j++){
            cin>>number;
            if(number)
                {
                    pi=i;
                    pj=j;
                }
        }
    }
    cout<<(abs(pi-3)+abs(pj-3));


    return 0;
}