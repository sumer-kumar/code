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

int divide(long long int a,long long int b)
{
	long long int sign = ((a<0) ^ (b<0)) ? -1:1;

	a = abs(a);
	b = abs(b);

	long long quotient = 0, temp = 0;

	  for (int i = 31; i >= 0; --i) {
	 
	    if (temp + (b << i) <= a) {
	      temp += b << i;
	      quotient |= 1LL << i;
	    }
	  }
	 
	  return sign*quotient;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a , b ;  //a/b;
	cin>>a>>b;
	cout<<'('<<a<<')'<<"/("<<b<<") : "<<divide(a,b)<<endl;


	return 0;
}