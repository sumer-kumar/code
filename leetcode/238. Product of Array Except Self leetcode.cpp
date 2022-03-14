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


void solve(vi &a)
{
	int size = a.size();
	vi res(size,1);

	int curr=1;
	//from left to right
	rep(i,0,size-1)
	{
		res[i]*=curr;
		curr *= a[i];
	}
	
	curr = 1;
	//from right to left
	for(int i=size-1;i>=0;i--)
	{
		res[i] *= curr;
		curr *= a[i];
	}

	for(int x : res)
	{
		cout<<x<<" ";
	}
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	/*Input: nums = [1,2,3,4]*/
    vi a = {1,2,3,4};

    solve(a);

	return 0;
}

