#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(0);
    int n;
    cin>>n;
    ull steps = 0;
    vector<ull>a(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<a[i];
    }

    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            steps = steps+a[i]-a[i-1];
            a[i]=a[i-1];
            }

    }
    cout<<steps;
    return 0;
}