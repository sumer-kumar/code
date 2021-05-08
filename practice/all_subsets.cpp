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

void allsubsets(int a[],int size)
{
	// cout<<(1<<size)<<endl;
	for(int i=0;i<(1<<size);i++)
	{

		int x = i;
		int j=0;
		while(x)
		{
			if(x&1)//if there is set bit
				cout<<a[j]<<" ";
			j++;
			x=x>>1;
		}
		cout<<endl;
	}
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	allsubsets(a,n);	

	return 0;
}