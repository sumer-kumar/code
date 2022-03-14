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

vector<string> recur(string &a)
{
	vector<string> res;
	a.pb('/');

	int size = a.size();
	vi ind;


	rep(i,0,size-1)
	{
		if(a[i]=='/')
			ind.pb(i);
	}

	size = ind.size();

	for(int x : ind)
		cout<<x<<" ";
	cout<<endl;

	rep(i,1,size-1)
	{
		if(ind[i]-ind[i-1]>1)
		res.pb(a.substr(ind[i-1]+1,ind[i]-ind[i-1]-1));
	}

	return res;
}

string solve(string &a)
{
	vector<string> token = recur(a);

	string res = "/";

	stack<int> st;

	int size = token.size();

	rep(i,0,size-1)
	{
		if(token[i]=="..")
		{
			if(!st.empty())
				st.pop();
		}
		else if(token[i]==".")
		{
			continue;
		}
		else
		{
			st.push(i);
		}
	}


	stack<int> st2;

	while(!st.empty())
	{
		st2.push(st.top());
		st.pop();
	}

	while(!st2.empty())
	{
		res += token[st2.top()] + "/";
		st2.pop();
	}

	if(res.size()!=1)
	res.pop_back();

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a= "/../";

    cout<<solve(a)<<endl;

	return 0;
}

