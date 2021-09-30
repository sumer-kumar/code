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


int recur(vector<bool> &vis,int curr,int n)
{


	if(curr>n)
		return 1;

	int res = 0;
	rep(i,1,n)
	{	
		if(vis[i]==false && (i%curr==0 || curr%i==0))
		{
			vis[i]=true;
			res += recur(vis,curr+1,n);
			vis[i]=false;
		}
	}

	return res;
}


int solve(int n)
{
	vector<bool> vis(n+1,false);
	return recur(vis,1,n);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 4;

    cout<<solve(n)<<endl;

	return 0;
}

