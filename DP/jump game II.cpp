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
		return 0;

	if(a[0]==0)
		return -1;

	int max_reach = a[0];
	int jump_remain = a[0];

	int jump_taken = 1;

	rep(curr,1,size-1)
	{
		if(curr==size-1)
			return jump_taken;

		max_reach=max(max_reach,curr+a[curr]);

		jump_remain--;

		if(jump_remain==0)
		{
			if(curr>=max_reach)
				return -1;
			jump_taken++;
			jump_remain = max_reach-curr;

		}
	}
	return jump_taken;

}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a={0,1};

    cout<<solve(a)<<endl;

	return 0;
}