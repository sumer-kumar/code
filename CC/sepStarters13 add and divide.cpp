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


string solve(ll a,ll b)
{

	if(a==1)
		return "YES";
	if(b==1)
		return "NO";

	ll gc = __gcd(a,b);

	/*(a / gcd(a, b)) * b*/

	ll lc = (a/gc)*b;

	double sq = sqrt(LLONG_MAX);

	for(ll i=1;i<sq;i++)
	{
		ll p = pow(b,i);
		if(p>=lc)
		{
			if(p%lc==0)
				return "YES";
			break;
		}
	}

	return "NO";

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	ll a,b;
    	cin>>a>>b;

    	cout<<solve(a,b)<<endl;
    }

	return 0;
}

