#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;


void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

void find_min_max(vi a,int &mn,int &mx)
{	/*we have to find the index not the value*/
	int mini = 0;
	int maxi = 0;

	rep(i,1,a.size()-1)
	{
		if(a[mini]>a[i])
			mini = i;

		if(a[maxi]<a[i])
			maxi = i;
	}
	mn = mini;
	mx = maxi;
}

void recur(vector<int> &a)
{
	int size = a.size();

	/*index of maximum and minimum*/
	int mn,mx;

	find_min_max(a,mn,mx);

	if(a[mn]==0 && a[mx]==0)
		return;

	int netmin = min(-a[mn],a[mx]);

	cout<<mn<<" pays "<<netmin<<" to "<<mx<<endl;

	a[mn] += netmin;
	a[mx] -= netmin;
	recur(a);
}

void mincash_flow(vvi a)
{
	int size = a.size();
	vi amount(size,0);

	/*fill the amount*/
	rep(i,0,size-1)
	{
		rep(j,0,size-1)
		amount[i] += a[j][i] - a[i][j];
	}
	recur(amount);
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vvi graph = { {0, 1000, 2000},
                  {0, 0, 5000},
                  {0, 0, 0}};	

    mincash_flow(graph);
	return 0;
}