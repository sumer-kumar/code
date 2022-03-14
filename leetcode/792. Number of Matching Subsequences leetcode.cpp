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


int solve(string &s,vector<string> &a)
{

	unordered_map<char,vi> um;
	
	int size = s.size();

	rep(i,0,size-1)
	um[s[i]].pb(i);

	int cnt=0;

	for(auto &x : a)
	{
		int prev = -1;
		bool flag=true;
		int sizex = x.size();

		rep(i,0,sizex-1)
		{
			auto it = upper_bound(um[x[i]].begin(),um[x[i]].end(),prev);

			if(it==um[x[i]].end())
			{
				flag=false;
				break;
			}
			else
			{
				prev = *it;
			}
		}

		if(flag==true)
			cnt++;
	}

	return cnt;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3*/

    /*Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2*/

    string s = "dsahjpjauf";
    vector<string> a = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};

    cout<<solve(s,a)<<endl;

	return 0;
}

