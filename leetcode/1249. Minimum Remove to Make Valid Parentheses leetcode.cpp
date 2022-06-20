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

void recur(string &a,int i,int curr)
{
	if(i==a.size())
		return ;

	if(a[i]=='(')
	{
		recur(a,i+1,curr+1);
	}
	else if(a[i]==')')
	{
		if(curr>0)
		{
			recur(a,i+1,curr-1);
		}
		else
		{
			a[i]='#';
			recur(a,i+1,curr);
		}
	}
	else
	{
		recur(a,i+1,curr);
	}
}

void reverse(string &a)
{
	reverse(a.begin(),a.end());
	for(char &x : a)
	{
		if(x=='(')
			x=')';
		else if(x==')')
			x='(';
	}
}

string solve(string &a)
{
	reverse(a);
	recur(a,0,0);
	reverse(a);
	recur(a,0,0);

	string res = "";

	for(char x : a)
	{
		if(x=='#')
			continue;
		res.pb(x);
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	/*Input: s = "lee(t(c)o)de)"
	Output: "lee(t(c)o)de"*/

	string a = "le(e(t(c)o)de";

	cout<<solve(a)<<endl;

	return 0;
}

