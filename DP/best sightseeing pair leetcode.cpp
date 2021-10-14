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

	int prev_best = a[0]+0;
	int curr_best = 0;

	for(int i=1;i<size;i++)
	{
		curr_best = max(curr_best,prev_best+a[i]-i);
		prev_best = max(prev_best,a[i]+i);
	}

	return curr_best;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {8,1,5,2,6};

    cout<<solve(a)<<endl;

	return 0;
}

