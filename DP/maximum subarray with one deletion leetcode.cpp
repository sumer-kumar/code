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
	vi l(size,0);
	vi r(size,0);

	/*from left side*/
	/*maximum size if we include current ith element*/
	int curr_mx = a[0];
	int res_mx = a[0];
	l[0]=a[0];
	rep(i,1,size-1)
	{
		curr_mx = max(a[i]+curr_mx,a[i]);
		res_mx = max(res_mx,curr_mx);
		l[i]=curr_mx;		
	}

	/*from right side*/
	/*maximum size if we include current ith element*/
	curr_mx = a[size-1];
	r[size-1] = a[size-1];
	for(int i=size-2;i>=0;i--)
	{
		curr_mx = max(curr_mx+a[i],a[i]);
		r[i] = curr_mx;
	}

	int mx = res_mx;
	/*if deleting (i+1)th element*/
	rep(i,1,size-2)
	{
		mx = max(mx,l[i-1]+r[i+1]);
	}	

	return mx;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,-2,-2,3};

    cout<<solve(a)<<endl;

	return 0;
}

