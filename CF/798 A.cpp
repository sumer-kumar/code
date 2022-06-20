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


string solve(string &a,string &b,int k)
{
	priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq1,pq2;

	unordered_map<char,int> um1,um2;

	for(char x : a) um1[x]++;
	for(char x : b) um2[x]++;

	int next_turn = 0; //0 1 2 
	int remain = k;

	for(auto x : um1) pq1.push({x.first,x.second});
	for(auto x : um2) pq2.push({x.first,x.second});

	string res = "";
	int last = 0;
	while(!pq1.empty() && !pq2.empty())
	{
		if(next_turn!=0)
			remain = k;
		if(next_turn==1 || (pq1.top().first<=pq2.top().first && next_turn==0))
		{
			if(last==2)
				remain=k;
			auto t = pq1.top();
			pq1.pop();

			remain--;
			t.second--;

			res.pb(t.first);

			if(remain==0)
				next_turn = 2;
			else
				next_turn = 0;

			if(t.second>0)
				pq1.push(t);
			last=1;
		}
		else
		{
			if(last==1)
				remain=k;
			auto t = pq2.top();
			pq2.pop();

			remain--;
			t.second--;

			res.pb(t.first);

			if(remain==0)
				next_turn = 1;
			else
				next_turn = 0;

			if(t.second>0)
				pq2.push(t);
			last=2;
		}
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	int n,m,k;
    	cin>>n>>m>>k;

    	string a,b;
    	cin>>a>>b;

    	cout<<solve(a,b,k)<<endl;
    }

	return 0;
}

