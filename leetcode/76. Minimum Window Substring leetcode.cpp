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


int solve(string &a,string &b)
{
	unordered_map<char,int> um;

	int sizea = a.size();
	int sizeb = b.size();

	for(char x : a)
		um[x]++;

	for(int i=0;i<size;i++)
	{
		
	}

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"*/

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout<<solve(s,t)<<endl;

	return 0;
}

