#include <bits/stdc++.h>
using namespace std;
#define ll long long

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
	//exp(x) e^x
	//sin(x) x in radians
double fx(double x)
{
	return x*exp(x)-cos(x);
}


double valueOfx(double x1,double x2){

	return (x1*fx(x2)-x2*fx(x1))/(fx(x2)-fx(x1));

}




int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1,x2;
    cin>>x1>>x2;
    cout<<"value of x : "<<valueOfx(x1,x2)<<endl;
    cout<<"value of fx : "<<fx(x1);

	return 0;
}

