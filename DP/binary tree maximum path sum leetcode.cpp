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

struct node {
	int data;
	struct node* left;
	struct node* right;
	node(){
		left=NULL;
		right=NULL;
	}
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* createTree();
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);

int recur(node* root,int &res)
{
	if(root==NULL)
		return 0;

	int l = recur(root->left,res);
	int r = recur(root->right,res);

	/*including current node and left right both*/
	int m1 = l+r+root->data;

	/*including max of left and right with current node*/
	int m2 = max(l,r)+root->data;

	/*do not including any node from left and right*/
	int m3 = root->data;

	res = max({res,m1,m2,m3});

	return max(m2,m3);
}

int solve(node* root)
{
	int res = INT_MIN;
	recur(root,res);
	return res;
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


void postorder(node* top)
{
	stack<node*> st;
	st.push(top);
	node* prev = NULL;
	node* root = top;
	while(!st.empty())
	{
		while(root)
		{	
			if(root!=top)
			st.push(root);
			// prev = root;
			root=root->left;
		}
		while(root==NULL&&!st.empty()){
			root = st.top();
			if(root->right==NULL||root->right==prev)
			{
				cout<<root->data<<" ";
				st.pop();
				prev = root;
				root = NULL;
			}
			else
			root=root->right;
		}
	}
}



void preorder(node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}


node* createTree()
{
	node* root = new node();
	cin>>root->data;
	queue<node*> st;
	st.push(root);

	while(!st.empty())
	{	
		node* t = st.front();
		st.pop();//popping

		int l,r;
		// cout<<"enter left right for "<<t->data<<": \n";
		cin>>l>>r;

		if(l!=-1)
		{
			node* left = new node(l);
			t->left = left;
			st.push(left);	
		}
		if(r!=-1)
		{
			node* right  = new node(r);
			t->right = right;
			st.push(right);
		}
	}

	return root;
}