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

unordered_map<int,int> um;
int recur(int n)
{

	if(n==1)
		return 0;

	if(um.find(n)!=um.end())
		um[n];

	if(n&1) /*odd*/
	{
		return um[n] = 1 + min(recur(n+1),recur(n-1));
	}
	else /*even*/
	{	
		return um[n] = 1+recur(n/2);
	}
}

int solve(int n)
{
	um.clear();
	return recur(n);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 7;

    cout<<solve(n)<<endl;

	return 0;
}

