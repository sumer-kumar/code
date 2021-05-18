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

int platforms(int arr[],int dep[],int size)
{
	multimap<int,int> m;

	for(int i=0;i<size;i++)
	{
		// m[arr[i]] = 1;
		m.insert(make_pair(arr[i],1));
		
		// m[dep[i]] = -1;
		m.insert(make_pair(dep[i],-1));
	}

	int count = 0;
	int maxCount = 0;
	for(auto x = m.begin();x!=m.end();x++)
	{
		count += x->second;
		maxCount  = max(maxCount,count);
	}
	return maxCount;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};	
	int size=6;

	cout<<platforms(arr,dep,size)<<endl;
	return 0;
}