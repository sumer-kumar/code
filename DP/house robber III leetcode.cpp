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

struct node 
{
	int data;
	node* left;
	node* right;

	node()
	{
		this->data = 0;
		this->left = NULL;
		this->right = NULL;
	}

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	node(int data,node* left, node* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

};

node* createTree()
{
	node* root = new node();
	cin>>root->data;

	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		int l,r;
		cin>>l>>r;

		node* curr = q.front();
		q.pop();
		if(l!=-1)
		{
			curr->left = new node(l);
			q.push(curr->left);
		}

		if(r!=-1)
		{
			curr->right = new node(r);
			q.push(curr->right);
		}
	}

	return root;

}

void preorder(node* root)
{
	if(root==NULL)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

/*

	state 0 : can rob this house
	state 1 : cannot rob this house

*/

unordered_map<node*,int> um0;
unordered_map<node*,int> um1;
int recur(node* root,int state)
{

	if(root==NULL)
		return 0;

	if(state == 0)
	{
		if(um0.find(root)!=um0.end())
			return um0[root];
		
		return um0[root] = max(
				root->data + recur(root->left,1)+recur(root->right,1),
				recur(root->left,0) + recur(root->right,0)
			);
	}
	else
	{
		if(um1.find(root)!=um1.end())
			return um1[root];
		return um1[root] = recur(root->left,0) + recur(root->right,0);
	}
}


int solve(node* root)
{
	um0.clear();
	um1.clear();
	return recur(root,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node* root = createTree();

    preorder(root);
    cout<<endl;


    cout<<solve(root)<<endl;

	return 0;
}

