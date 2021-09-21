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

	if(size==1)
		return a[0];

	int p_max  = 0;
	int n_max = 0;

	int o_max = INT_MIN;

	rep(i,0,size-1)
	{
		if(a[i]>0)
		{
			p_max = max(p_max*a[i],a[i]);
			n_max = min(n_max*a[i],a[i]);

			o_max = max(o_max,p_max);
		}	
		else if(a[i]<0) 
		{
			swap(p_max,n_max);

			p_max = max(p_max*a[i],a[i]);
			n_max = min(n_max*a[i],a[i]);

			o_max = max(o_max,p_max);

		}
		else
		{
			p_max = 0;
			n_max = 0;
			o_max = max(o_max,0);
		}
	}

	return o_max;

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {-1};

    cout<<solve(a)<<endl;

	return 0;
}

