#include <bits/stdc++.h>
using namespace std;
#define int long long int

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int solve(int a[],int b[],int size1,int size2)
{
	int suma = 0;
	int sumb = 0;
	int sum = 0;
	int i=0;
	int j=0;

	while(i<size1&&j<size2)
	{
		if(a[i]<b[j])
		{
			suma+=a[i];
			i++;
		}
		else if(a[i]>b[j])
		{
			sumb+=b[j];
			j++;
		}
		else /*(when they are equal ) i.e intersection point
				now we have to decide which path to chose*/
		{
			sum+= max(suma,sumb)+a[i];
			// cout<<suma<<"   "<<sumb<<"-->"<<sum<<endl;
			suma = sumb = 0;
			i++; //increment the pointers
			j++;
		}
	}
	while(i<size1)
	{
		suma+=a[i];
		i++;
	}
	while(j<size2)
	{
		sumb+=b[j];
		j++;
	}
	// cout<<suma<<"   "<<sumb<<endl;
	sum+=max(suma,sumb);
	return sum;
}

int32_t main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	while(true)
	{
		int size1;
		cin>>size1;

		if(size1==0)
			return 0;
		int a[size1];
		for(int i=0;i<size1;i++)
		{
			cin>>a[i];
		}
		int size2;
		cin>>size2;
		int b[size2];
		for(int i=0;i<size2;i++)
			cin>>b[i];

		cout<<solve(a,b,size1,size2)<<endl;
	}

	return 0;
}