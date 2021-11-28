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
unordered_map<string,bool> um;
bool recur(string a,unordered_set<string> &st)
{
	int size = a.size();

	if(um.find(a)!=um.end())
		return um[a];

	rep(i,0,size-1)
	{
		string prefix = a.substr(0,i);
		string suffix = a.substr(i); 
		if(st.find(prefix)!=st.end() && (st.find(suffix)!=st.end() || recur(suffix,st)))
			return um[a] = true;
	}
	return um[a] = false;
}

int solve(vector<string> &a)
{	
	um.clear();
	unordered_set<string> st(a.begin(),a.end());
	vector<string> res;
	for(string &x : a)
	{
		if(recur(x,st))
			res.pb(x);
	}

	for(string &x : res)
		cout<<x<<endl;
	return res.size();

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]*/

    vector<string> a = {"cat","cats","catsdogcats","dog",
    					"dogcatsdog","hippopotamuses","rat",
    					"ratcatdogcat"};

 	cout<<solve(a)<<endl;

	return 0;
}

