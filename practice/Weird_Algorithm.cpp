#include <iostream>
using namespace std;

int main(){

    long int number;
    //taking number input
    cin>>number;

    while(number!=1){
        cout<<number<<" ";

        if(number%2==0)
            number/=2;
        else
        {
            number*=3;
            number++;
        }
        
    }
    cout<<1;
    return 0;
}