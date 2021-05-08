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

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int num,i;

	cin>>num>>i;

	if(num&1<<i)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}