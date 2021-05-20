#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int maxXor(vi a)
{
	int maxx = 0;
	int currMaxx = 0;

	rep(i,0,a.size()-1)
	{
		currMaxx = max(a[i],a[i]^currMaxx);
		maxx = max(maxx,currMaxx);
	}

	return maxx;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;

	vi a(n);
	rep(i,0,n-1)
	cin>>a[i];

	// cout<<maxXor(a)<<endl;
	cout<<(100000^99999^99998)<<endl;

	return 0;
}