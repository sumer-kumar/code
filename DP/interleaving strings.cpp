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

int dp[300][300];
bool recur(string &a,string &b,string &c,int aa,int bb)
{

	if(aa<0 && bb<0)
		return true;

	int cc;

	if(aa<0)
		cc=bb;
	else if(bb<0)
		cc=aa;
	else 
		cc = aa+bb+1;

	if(dp[aa+1][bb+1]!=-1)
		return dp[aa+1][bb+1];

	bool t1=false,t2=false;

	if(aa>=0 && a[aa]==c[cc])
		t1 = recur(a,b,c,aa-1,bb);

	if(bb>=0 && b[bb]==c[cc])
		t2 = recur(a,b,c,aa,bb-1);

	return dp[aa+1][bb+1] = t1 || t2;
}


bool solve(string a,string b,string c)
{
	memset(dp,-1,sizeof(dp));
	int aa = a.size();
	int bb = b.size();
	int cc = c.size();

	if(aa+bb!=cc)
		return false;

	return recur(a,b,c,aa-1,bb-1);

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,c;

    a="aabcc";
    b="dbbca";
    c="aadbbcbcac";

    cout<<solve(a,b,c)<<endl;

    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
	string s1 = "", s2 = "", s3 = "";
    // cout<<solve(s1,s2,s3)<<endl;


	return 0;
}

