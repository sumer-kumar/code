#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long int number;
    long int sum;

    cin>>number;
    sum=number*(number+1)/2;
    long int curr;
    for(int i=1;i<number;i++){
        cin>>curr;
        sum-=curr;
    }
    cout<<sum;

    return 0;

}