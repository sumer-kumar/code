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

//this recursion is only to solve the fraction part
void recur(int n,int d,string &res,int curr,unordered_map<int,int> um)
{
	int t = n/d;
	int r = n%d;

	if(um.count(r)!=0 && res[um[r]] == t+'0')
	{
		res = res.substr(0,um[r])+"("+res.substr(um[r])+")";
		return;
	}

	um[r] = curr;

	res.pb(t+'0');

	if(r!=0)
	recur(r*10,d,res,curr+1,um);
}

string solve(int n,int d)
{
	string res1 = "";

	string sign = (n<0 ^ d<0)?"-":"";

	n = abs(n);
	d = abs(d);

	unordered_map<int,int> st;
	int t = n/d;
	int r = n%d;
	res1 = to_string(t);

	if(r==0)
		return res1;

	string res2="";
	recur(r*10,d,res2,0,st);

	return sign+res1+"."+res2;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = -50;
    int d = 8;

    cout<<solve(n,d)<<endl;

	return 0;
}

