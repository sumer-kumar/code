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


bool isPali(string &a)
{
	int start = 0;
	int end = a.size()-1;

	while(start<end)
	{
		if(a[start]!=a[end])
			return false;
		start++;
		end--;
	}

	return true;
}

void recur(string a,vector<string> &curr,vector<vector<string>> &res)
{
	// cout<<a<<endl;

	if(isPali(a))
	{
		curr.pb(a);
		res.pb(curr);
		curr.pop_back();
		// return ;
	}


	int size = a.size();

	rep(i,1,size-1)
	{
		string t = a.substr(0,i); 
		if(isPali(t))
		{
			curr.pb(t);
			recur(a.substr(i),curr,res);
			curr.pop_back();
		}
	}
}

int solve(string &a)
{
	int size = a.size();
	vector<string> curr;
	vector<vector<string>> res;

	recur(a,curr,res);

	for(auto x : res)
	{
		for(string p : x)
		{
			cout<<p<<" ";
		}
		cout<<endl;
	}

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "bb";

    solve(a);

	return 0;
}

