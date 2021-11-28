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

void recur(string &s,int start,string curr,unordered_set<string> &st,vector<string> &res)
{
	int size = s.size();
	if(start == size)
	{
		res.pb(curr);
	}

	rep(i,start,size-1)
	{
		if(st.find(s.substr(start,i-start+1))!=st.end())
		{
			string t = curr + s.substr(start,i-start+1) + " ";
			recur(s,i+1,t,st,res);
		}
	}
}

void solve(string &s,vector<string> &wordDict)
{
	/*for fast searching*/
	unordered_set<string> st(wordDict.begin(),wordDict.end());
	vector<string> res;
	recur(s,0,"",st,res);

	for(string x : res)
		cout<<x<<endl;
}


/*
vector<string> solve(string s, unordered_set<string>& wordDict) {
unordered_map<int, vector<string>> memo {{s.size(), {""}}};
function<vector<string>(int)> sentences = [&](int i) {
    if (!memo.count(i))
        for (int j=i+1; j<=s.size(); j++)
            if (wordDict.count(s.substr(i, j-i)))
                for (string tail : sentences(j))
                    memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
    return memo[i];
};
    return sentences(0);
}
*/


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*	Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
	Output: ["cats and dog","cat sand dog"]*/

    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};

    solve(s,wordDict);

	return 0;
}

