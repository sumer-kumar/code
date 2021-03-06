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


bool is_valid(unordered_map<char,int> &a,unordered_map<char,int> &b)
{
	for(auto x : b)
	{
		if(x.second > a[x.first])
			return false;
	}
	return true;
}

//find full a in smallest b
string solve(string &a,string &b)
{
	int sizea = a.size();
	int sizeb = b.size();

	if(sizeb<sizea)
		return "";

	unordered_map<char,int> uma;
	unordered_map<char,int> um;

	for(char x : a)
		uma[x]++;

	int l=0;
	int r=sizeb;

	int start=0;

	bool flag=false;

	rep(i,0,sizeb-1)
	{
		um[b[i]]++;
		while(is_valid(um,uma))
		{
			if(r-l+1>i-start+1)
			{
				flag=true;
				l=start;
				r=i;
			}

			um[b[start++]]--;
		}
	}

	return !flag?"":b.substr(l,r-l+1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"*/

    string s = "AAAAAABBBBB";
    string t = "ABC";

    cout<<solve(t,s)<<endl;

	return 0;
}

