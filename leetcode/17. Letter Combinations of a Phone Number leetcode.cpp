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

unordered_map<char,string> um = {
	{'2',"abc"},
	{'3',"def"},
	{'4',"ghi"},
	{'5',"jkl"},
	{'6',"mno"},
	{'7',"pqrs"},
	{'8',"tuv"},
	{'9',"wxyz"}
};

void recur(string &a,int curr,string op,vector<string> &res)
{
	if(curr==a.size())
	{
		if(op.size()>0)
		res.pb(op);
		return;
	}
	int size = um[a[curr]].size();
	rep(i,0,size-1)
	{	
		op.pb(um[a[curr]][i]);
		recur(a,curr+1,op,res);
		op.pop_back();
	}
}

void solve(string &a)
{
	vector<string> res;
	recur(a,0,"",res);

	for(string x : res)
		cout<<x<<" ";
	cout<<endl;

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]*/

    string a = "23";

	solve(a);

	return 0;
}

