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



int solve(int n,int r,int c)
{
	int cr = (n+1)/2;
	int cc = (n+1)/2;

	int diff = cr-r;

	r = cr;

	if(c+diff>0 && c+diff<=n)
		c = c+diff;
	else
		c = c-diff;
	return abs(cr-c)%2;
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
    	int n,r,c;
    	cin>>n>>r>>c;
    	cout<<solve(n,r,c)<<endl;
    }

	return 0;
}

