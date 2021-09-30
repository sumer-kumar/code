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


int solve(vi &a,int n)
{
	int size = a.size();
	vi ind(size,0);

	vi res;

	res.pb(1);

	while(res.size()<n)
	{
		//finding minimum
		int curr_min = INT_MAX;
		rep(i,0,size-1)
		{
			curr_min = min(curr_min,res[ind[i]]*a[i]);
		}

		res.pb(curr_min);

		/*update the indexes of primes having product with the value at 
		index is equal to curr_min*/

		rep(i,0,size-1)
		{
			if(a[i]*res[ind[i]]==curr_min)
				ind[i]++;
		}

	}
	// for(int x : res)
	// 	cout<<x<<",";
	// cout<<endl;

	return res.back();
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,7,13,19};
    int n=12;

    cout<<solve(a,n)<<endl;

	return 0;
}

