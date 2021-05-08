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

void solve(int a[],int size,vector<int>&v)
{
	for(int i=0;i<(1<<size);i++)
	{
		int sum = 0;
		int j = 0;
		int x = i;
		while(x)
		{
			if(1&x)
				sum+=a[j];
			j++;
			x=x>>1;
		}
		v.push_back(sum);
	}
	/*For printing the vector*/
	// for(auto x : v)
	// {
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// for(int i=0;i<size;i++)
	// 	cout<<a[i]<<" ";
	// cout<<'\n';
}

int32_t main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size,a,b;
    cin>>size>>a>>b;
    int ar[size];
    for(int i=0;i<size;i++)
    {
    	cin>>ar[i];//input
    }
	vector<int> a1;
	vector<int> a2;
	/*Solve function will fill the vector a1 and a2 with their subset sums 
	respectively*/
	solve(ar,size/2,a1);
	solve(ar+size/2,(size+1)/2,a2);

	sort(a2.begin(),a2.end());//sort in ascending order

	int count  = 0;
	for(int i=0;i<a1.size();i++)
	{
		int lower = lower_bound(a2.begin(),a2.end(),a-a1[i])-a2.begin();
		int upper = upper_bound(a2.begin(),a2.end(),b-a1[i])-a2.begin();
		count+=upper-lower;
	}
	cout<<count<<endl;

	return 0;
}

















