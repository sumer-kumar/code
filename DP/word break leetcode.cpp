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
bool recur(string s,unordered_set<string> &st)
{

	if(st.find(s)!=st.end())
		return true;

	if(um.find(s)!=um.end())
		return um[s];

	int size = s.size();

	rep(i,1,size-1)
	{
		if(st.find(s.substr(0,i))!=st.end() && recur(s.substr(i),st))
			return um[s] = true;
	}
	return um[s] = false;
}

bool solve(string &s,vector<string> &a)
{
	um.clear();
	unordered_set<string> st(a.begin(),a.end());

	return recur(s,st);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // s = "leetcode", wordDict = ["leet","code"]

    string s = "leetleetleetleetcodecode";
    vector<string> a = {"leet","code"};

    cout<<solve(s,a)<<endl;

	return 0;
}

