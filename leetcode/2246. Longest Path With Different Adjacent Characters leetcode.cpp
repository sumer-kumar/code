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

unordered_map<int,set<int,greater<int>>> um;

void recur(vi &parent,int curr,string &s,int tt)
{

	if(tt!=0)
	um[curr].insert(tt);

	if(curr==0)
		return;


	if(s[parent[curr]] == s[curr])
	{
		recur(parent,parent[curr],s,0);
		return ;
	}

	recur(parent,parent[curr],s,tt+1);

}

int recur2(int size)
{
	int res = 0;
	rep(i,0,size-1)
	{
		if(um[i].size()>=2)
		{
			auto it = um[i].begin();
			res = max(res, 1 + *(it) + *(++it));
		}
		else
		{
			res = max(res,*(um[i].begin()));
		}
	}
	return res;
}

int solve(vi &parent,string &s)
{
	um.clear();
	unordered_map<int,bool> um1;
	int size = parent.size();

	if(size<=1)
		return size;

	rep(i,1,size-1)
	{
		um1[i]=true;
	}

	rep(i,1,size-1)
	{
		um1[parent[i]]=false;
	}

	int res = 0;

	rep(i,1,size-1)
	{
		if(um1[i]==true)
			recur(parent,i,s,0);
	}

	for(auto x : um)
	{
		cout<<x.first<<endl;
		for(int p : x.second)
			cout<<p<<" ";
		cout<<"\n\n";
	}



	return recur2(parent.size());
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3*/

    vi parent = {-1,0,0,1,1,2};
    string s = "abacbe";

    cout<<solve(parent,s)<<endl;

	return 0;
}

