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

int solve(vi &a)
{
	int size = a.size();

	unordered_map<int,int> um;
	for(int x : a)
		um[x]++;


	sort(a.begin(),a.end());
	int res = 1;//for the first element

	rep(i,1,size-1)
	{
		rep(j,0,i-1)
		{
			if(a[i]%a[j]==0)
			{
				if(um.find(a[i]/a[j])!=um.end())
				{
					um[a[i]] = (um[a[i]]+(1ll*um[a[j]]*(um[a[i]/a[j]]))%mod)%mod;
				}
			}
		}
		res = (res + um[a[i]])%mod;
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,4,5,10};

    cout<<solve(a)<<endl;

	return 0;
}

