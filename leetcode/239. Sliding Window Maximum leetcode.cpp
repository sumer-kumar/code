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


void solve(vi &a,int k)
{
	int size = a.size();
	vi res;

	deque<int> d;

	rep(i,0,size-1)
	{
		if(!d.empty() && i-k==d.front()) 
			d.pop_front();

		while(!d.empty() && a[d.back()]<=a[i])
			d.pop_back();

		d.pb(i);

		if(i>=k-1)
			res.pb(a[d.front()]);
	}
	for(int x : res)
		cout<<x<<" ";
	cout<<endl;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
	Output: [3,3,5,5,6,7]*/

    vi a = {1,3,-1,-3,5,3,6,7};
    int k=3;

    solve(a,k);

	return 0;
}

