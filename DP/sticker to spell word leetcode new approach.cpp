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

string effect(string &a,string &remain)
{
	unordered_map<char,int> um;
	for(char x : a)
		um[x]++;

	string res = "";

	for(char x : remain)
	{
		if(um.find(x)!=um.end() && um[x]>0)
		{
			um[x]--;
			continue;
		}
		res.pb(x);
	}

	return res;
}
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int,string>,int,hash_pair> um;
int recur(vector<string> &a,int curr,string &remain)
{

	if(remain.size()==0)
		return 0;
	if(curr==a.size())
	{
		if(remain.size()==0)
			return 0;
		return 100000;
	}

	if(um.find({curr,remain})!=um.end())
		return um[{curr,remain}];

	int m1=100000;
	int m2=100000;

	/* try choose current element*/
	string after_effect = effect(a[curr],remain);

	if(after_effect.size()<remain.size())
		m1 = 1 + recur(a,curr,after_effect);
	m2 = recur(a,curr+1,remain);

	return um[{curr,remain}] = min(m1,m2);	
}

int solve(vector<string> &a,string &target)
{
	um.clear();
	return recur(a,0,target);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a = {"these","guess","about","garden","him"};
    string target = "atomher";

    cout<<solve(a,target)<<endl;

	return 0;
}

