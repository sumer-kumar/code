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

int dp2[1001];
int recur2(vector<pii> &a,int curr)
{

	if(curr>=a.size())
		return 0;

	if(dp2[curr]!=-1)
		return dp2[curr];

	int m1=0,m2=0;

	if(curr<a.size() && a[curr].fi+1==a[curr+1].fi)
		m1 = a[curr].fi*a[curr].se + recur2(a,curr+2);
	else
		m1 = a[curr].fi*a[curr].se + recur2(a,curr+1);

	m2 = recur2(a,curr+1);

	// cout<<a[curr].fi<<" "<<curr<<" "<<m1<<" "<<m2<<endl;

	return dp2[curr] = max(m1,m2);

}


int solve2(vi &A)
{

	memset(dp2,-1,sizeof(dp2));
	vector<pii> a;
	unordered_map<int,int> um;

	int size = A.size();

	if(size==1)
		return A[0];

	rep(i,0,size-1)
	{
		um[A[i]]++;
	}

	for(auto x : um)
	{
		a.pb({x.fi,x.se});
	}

	sort(a.begin(),a.end());

	size = a.size();
	unordered_map<int,bool> um2;
	// for(auto x : a)
	// 	cout<<x.fi<<' '<<x.se<<endl;
	// cout<<endl;

	return recur2(a,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	//  0 1 2 3 4 5 6
    vi a = {3,1}; /*ans : 9*/

    cout<<solve2(a)<<endl;

	return 0;
}
