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

void printMaxActivities(int s[],int f[],int n)
{
	vector<pair<int,int>> a; /*finish time and start timer*/
	
	/*fill the pair with finish and start time resp.*/
	for(int i=0;i<n;i++)
	{
		a.push_back({f[i],s[i]});
	}

	/*sort wrt finish timer*/
	sort(a.begin(),a.end());
	int cnt = 1;
	int curr = 0;
	cout<<a[curr].second<<" --> "<<a[curr].first<<endl;

	for(int i=1;i<n;i++)
	{
		if(a[i].second >= a[curr].first)
		{
			cout<<a[i].second<<" --> "<<a[i].first<<endl;
			curr = i;
			cnt++;
		}
	}
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s[] =  {1, 3, 0, 5, 5, 8};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);

	return 0;
}