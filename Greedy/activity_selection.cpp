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

int activity_sel(vi &s,vi &f)
{	
	int n = s.size();
	vector<pii> p; /*finish time and start time*/

	rep(i,0,n-1)
	p.pb(mp(f[i],s[i]));

	sort(p.begin(),p.end());
	// rep(i,0,n-1)
	// cout<<p[i].se<<" "<<p[i].fi<<endl;

	cout<<"-------------\n";
	int cnt = 1;
	int prev = p[0].fi;
	rep(i,1,n-1)
	{
		// cout<<prev<<" "<<p[i].se<<endl;
		if(prev < p[i].se)
		{
			cnt++;
			prev = p[i].fi;
		}
	}

	return cnt;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;

	vi s(n);	
	vi f(n);

	rep(i,0,n-1)
	cin>>s[i]>>f[i];

	cout<<activity_sel(s,f)<<endl;	

	return 0;
}