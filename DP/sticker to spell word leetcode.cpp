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

/*
	i have two option 
	1. to choose current element
		-> if choosing current element then see the effect what it does
		-> if it does nothing we are not going to choose it anyway
	2. to leave current element
		-> just move for the second element
*/

int effect(unordered_map<char,int> &um,string &curr)
{
	int cnt=0;
	for(char x : curr)
	{
		if(um.find(x)!=um.end() && um[x]>0)
		{
			um[x]--;
			cnt++;
		}
	}
	return cnt;
}

int dp[51][20];
int recur(vector<string> &a,int curr,int remain,unordered_map<char,int> um)
{

	if(remain<=0)
		return 0;

	if(curr==a.size())
	{
		if(remain==0)
			return 0;
		else
			return 100000;
	}

	// if(dp[curr][remain]!=-1)
	// 	return dp[curr][remain];

	int m1=100000;
	int m2=100000;

	/*do not current element*/
	m2 = recur(a,curr+1,remain,um);

	/*choose current element*/
	int cnt = effect(um,a[curr]);
	if(cnt>0)
		m1 = 1 + recur(a,curr,remain-cnt,um);

	cout<<curr<<" "<<cnt<<" "<<remain<<" "<<m1<<" "<<m2<<endl;

	return dp[curr][remain] = min(m1,m2);
}

int solve(vector<string> &a,string &target)
{
	memset(dp,-1,sizeof(dp));
	unordered_map<char,int> um;
	for(char x : target)
		um[x]++;

	int m = recur(a,0,target.size(),um);

	return m==100000?-1:m;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*Input: stickers = ["with","example","science"], target = "thehat"
		Output: 3*/
    /*["these","guess","about","garden","him"]
"atomher"*/

    vector<string> a = {"these","guess","about","garden","him"};
    string target = "atomher";


    cout<<solve(a,target)<<endl;

	return 0;
}

