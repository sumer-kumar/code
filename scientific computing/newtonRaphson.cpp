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

double fx(double x)
{
	//your function
	return pow(x,3)-3*x+1;
}

double dfx(double x)
{
	//your derivated function here
	return 3*pow(x,2)-3;
}

double valueofx2(double x)
{
	return x - fx(x)/dfx(x);
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	double x0;
	cin>>x0;

	int j;
	cin>>j;

	for(int i=0;i<j;i++)
	{
		cout<<"value of x"<<i<<" : "<<x0<<endl;
		double value = valueofx2(x0);
		cout<<"value of fx : "<<fx(x0);
		x0=value;
		cout<<"\n\n";

	}
	cout<<fx(1.53)<<endl;	

	return 0;
}