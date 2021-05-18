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


vector<int> minMax(int size,int c[],int k)
{
	/*sort*/
	sort(c,c+size);

	int cost = 0;
	int remain = size; /*ramining candies*/

	/*for minimum*/
	for(int i=0;remain>0;i++)
	{
		cost += c[i];
		remain--;

		for( int p = 0;p<k;p++)
			{
				remain--;
			}
	}
	vector<int> res;
	res.push_back(cost);

	cost = 0;
	remain = size;
	/*for maximum*/
	for(int i=size-1;remain>0;i--)
	{
		cost += c[i];
		remain--;

		for( int p = 0;p<k;p++)
		{
			remain--;
		}
	}

	res.push_back(cost);

	return res;
}
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	int candies[n];
	for(int i=0;i<n;i++)
		cin>>candies[i];

	int k;
	cin>>k;

	vector<int> res = minMax(n,candies,k);

	for(int x : res)
		cout<<x<<' ';

	return 0;
}
