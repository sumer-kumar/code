#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef priority_queue<int> pq_d;
typedef priority_queue<int,vector<int>,greater<int>> pq_a;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

bool cmp(pii &a,pii &b)
{
	if(a.se==b.se)
		return a.fi<b.fi;
	return a.se>b.se;
}

int solve(vi &pt,vi &gt)
{
	int size = pt.size();
	vector<pii> a(size);
	rep(i,0,size-1)
	{
		a[i].fi = pt[i];
		a[i].se = gt[i];
	}

	sort(a.begin(),a.end(),cmp);

	for(auto x : a)
		cout<<x.fi<<' '<<x.se<<endl;

	int mx = INT_MIN;
	int start=0;
	rep(i,0,size-1)
	{
		start += a[i].fi;
		mx = max(mx,start+a[i].se);
	}

	return mx;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*plantTime = [1,2,3,2], growTime = [2,1,2,1]*/
    /*plantTime = [1,4,3], growTime = [2,3,1]*/
    vi pt = {1,4,3};
    vi gt = {2,3,1};

    cout<<solve(pt,gt)<<endl;

	return 0;
}

