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

string extract(string a)
{
	string res = "";
	for(char x : a)
	{
		if(x!=' ')
			res.pb(x);
	}
	return res;
}

int solve(string &a)
{
	string s = extract(a); //remove spaces

	int sign = s[0]=='-'?-1:1;
	int nmb = 0;

	int size = s.size();
	rep(i,0,size-1)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			nmb = nmb*10 + (s[i]-'0');
			// cout<<nmb<<endl;
		}
	}
	return nmb*sign;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "    -42";

    cout<<solve(a)<<endl;

	return 0;
}

