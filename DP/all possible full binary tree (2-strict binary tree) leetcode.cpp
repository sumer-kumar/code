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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode node;

unordered_map<int,vector<node*>> um;
vector<node*> recur(int n)
{	
	if(n==1)
		return {new node(0)};

	if(um.find(n)!=um.end())
		return um[n];

	vector<node*> res;

	for(int i=1;i<n;i+=2)
	{
		vector<node*> l = recur(i);
		vector<node*> r = recur(n-i-1);

		for(auto left : l)
		{
			for(auto right : r)
			{
				node* root = new node(0,left,right);
				res.pb(root);
			}
		}
	}

	return um[n] = res;
}

int solve(int n)
{
	um.clear();
	vector<node*> res = recur(n);
	return res.size();
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=7;
    cout<<solve(n)<<endl;

	return 0;
}

