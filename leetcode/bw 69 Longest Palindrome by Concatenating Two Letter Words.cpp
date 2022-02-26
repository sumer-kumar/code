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


int solve(vector<string> &a)
{
	int cnt = 0;
	unordered_map<string,int> um;

	int size = a.size();

	for(int i=0;i<size;i++)
	{
		um[a[i]]++;
	}

	int one = 0;

	// for(auto x : um)
	// 	cout<<x.fi<<" "<<x.se<<endl;

	for(auto &x : um)
	{
		if(x.fi[0]==x.fi[1])
		{
			if(x.se>1)
			{
				cnt += 2*(x.se/2);
				int t = 2*(x.se/2);
				x.se = x.se - t;
			}
		}
		else 
		{
			string t = "";
			t.pb(x.fi[1]);
			t.pb(x.fi[0]);

			if(um.find(t)!=um.end())
			{
				cnt += 2*min(um[t],um[x.fi]);
				um[t]=0;
				um[x.fi]=0;
			}	
		}
	}

	for(auto x : um)
	{
		// cout<<x.fi<<" "<<x.se<<endl;
		if(x.fi[0]==x.fi[1] && x.se>=1)
		{
			cnt++;
			break;
		}
	}

	return 2*cnt;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a = {"lc","cl","gg"};
    cout<<solve(a)<<endl;

	return 0;
}

