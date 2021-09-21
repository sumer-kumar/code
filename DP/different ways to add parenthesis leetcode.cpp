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

unordered_map<string,vector<int>> um;
vector<int> recur(string a)
{
	vector<int> res;

	int size = a.size();
	if(size==0)
		return res;

	if(um.find(a)!=um.end())
		um[a];

	bool have_operator = false;

	rep(i,0,size-1)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*')
		{
			have_operator = true;
			vector<int> left = recur(a.substr(0,i));
			vector<int> right = recur(a.substr(i+1));

			for(int x : left)
			{
				for(int p : right)
				{
					if(a[i]=='-')
						res.pb(x-p);
					else if(a[i]=='+')
						res.pb(x+p);
					else
						res.pb(x*p);
				}
			}
		}
	}

	if(!have_operator)
	{
		return {stoi(a)};
	}

	return um[a] = res;
}

void solve(string &s)
{
	um.clear();
	vector<int> res = recur(s);

	for(int x : res)
		cout<<x<<" ";
	cout<<endl;

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "2*3-4*5";
    solve(a);

	return 0;
}

