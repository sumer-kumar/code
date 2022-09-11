#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll unsigned long long
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

int solve(ll n,ll x)
{
	queue<ll> q;
	q.push(x);
	int cnt = 0;
	unordered_set<ll> st;
	while(!q.empty())
	{
		int size = q.size();
		rep(i,0,size-1)
		{
			ll tp = q.front();
			q.pop();

			string a = to_string(tp);
			if(a.size()==n)
				return cnt;
			for(char x : a)
			{
				ll val = tp*(x-'0');
				if(val==0 || st.count(val))
					continue;
				q.push(val);
				st.insert(val);
			}
		}
		cnt++;
	}

	return -1;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;

    cin>>n>>x;

    cout<<solve(n,x)<<endl;

	return 0;
}

