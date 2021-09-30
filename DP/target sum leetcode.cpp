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

/*
	t for target sum
*/

string getHash(int a,int b)
{
	return to_string(a)+" "+to_string(b);
}

unordered_map<string,int> um;
int recur(vi &a,int n,int t)
{
	if(n==0 && t==0)
		return 1;
	if(n==0)
		return 0;

	if(um.count(getHash(n,t))!=0)
		return um[getHash(n,t)];

	return um[getHash(n,t)] = recur(a,n-1,t-a[n-1]) + recur(a,n-1,t+a[n-1]);
}

int solve(vi &a,int t)
{
	return recur(a,a.size(),t);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,1,1,1,1};
    int t = 3;

    cout<<solve(a,t)<<endl;

	return 0;
}

