#include <iostream>
using namespace std;

void sum(int *q,int q1,int q2);
int main() {

    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test,size,a[10000],q1,q2,n,q;
    cin>>test;
    while(test--){
        cin>>size;
        for(int i=0;i<size;i++){
            cin>>a[i];
        }
        cin>>q;
        while(q--){
        cin>>q1>>q2;
        sum(a,q1,q2);
        }
    }
	return 0;
}
void sum(int *q,int q1,int q2){
    int sum=0;
    q1--;
    q2--;
    for(int i=q1; i<=q2 ;i++){
        sum+=q[i];
    }
    cout<<sum<<endl;
}