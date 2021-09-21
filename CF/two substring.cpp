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

string solve(string &s)
{
	if(s.size()<=3)
		return "NO";
	//first search for AB 
	vi ab;
	int size = s.size();
	rep(i,0,size-2)
	{
		if(s[i]=='A' && s[i+1]=='B')
			ab.pb(i);
	}

	//second search for BA
	vi ba;
	rep(i,0,size-2)
	{
		if(s[i]=='B' && s[i+1]=='A')
		{
			ba.pb(i);

			if(ab.size()>2 && ba.size()>2)
				return "YES";
		}
	}

	if(ab.size()==0 || ba.size()==0)
		return "NO";

	if(ab.size()>1 && ba.size()>1)
		return "YES";

	for(int x : ab)
	{
		for(int p : ba)
		{
			if(abs(x-p)>1)
				return "YES";
		}
	}

	return "NO";
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    cout<<solve(s)<<endl;


	return 0;
}

