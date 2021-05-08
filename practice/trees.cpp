#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*Notes
	number of different trees of from n nodes --> 2^n-n
	*/


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
void levelorder(node* root);
int findMax(node* root);
int countNode(node* root);
void reverse_levelorder(node* root);
node* deeptestNode(node* root);
int leafnodes(node* root);
bool isIdentical(node* root1,node* root2);
int height(node* root);
int diameter(node* root);
void all_paths_to_leaves(node* root,string path = "");
void convertMirror(node* root);
node* lca(node* root,int one,int two );
node* tree_from_pre_and_in_order(string pre,string in);
void zigzagTraversal(node* root);
void showMap(map<int,int> om);
void verticalNodeSum(node* root);
void verticalNodeSumRecur(node* root,int col,map<int,int>&om);
int minimumDepth(node* root);


/*main------------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"wow";
    node* root = createTree();
    // node* root2 = createTree();
    node* temp = NULL;

    cout<<"minimum Depth : "<<minimumDepth(root);

	// cout<<"vertical node sum : ";
	// verticalNodeSum(root);

	// cout<<"\nzig-zag traversal : ";
	// zigzagTraversal(root);

    // cout<<"\nTree from pre and in oder : ";
    // temp = tree_from_pre_and_in_order("123456","324165");
    // cout<<"\ninorder : ";
    // preorder(temp);
    // cout<<"\npreorder : ";
    // inorder(temp);
    // cout<<"\npostorder : ";
    // postorder(temp); 

    // cout<<"\nlca for 4 7 id : ";
    // temp = lca(root,4,7);
    // cout<<temp->data<<endl;

    // /*convertMirror(root);*/

    // cout<<"all paths to leaves\n";
    // all_paths_to_leaves(root);

    // cout<<"\ndiameter : "<<diameter(root);

    // cout<<"\nheight : "<<height(root);

    // cout<<"\nis identical two trees : "<<isIdentical(root,root2);

    // cout<<"\nnumber of leaf nodes : "<<leafnodes(root);

    // cout<<"\ndeepest node : ";
    // temp = deeptestNode(root);
    // cout<<temp->data;

    // cout<<"\nreverse levelorder :";
    // reverse_levelorder(root);
    
    // cout<<"\nmax : "<<findMax(root);
    
    cout<<"\nsize of tree : "<<countNode(root);

    cout<<"\npreorder : ";
    preorder(root);
    
    cout<<"\ninorder : ";
    inorder(root);
	
	cout<<"\npostorder : ";
    postorder(root);
    
    cout<<"\nlevelorder : ";
    levelorder(root);	

	return 0;
}
/*main end----------------------------------------------->*/



/*further funtions--------------------------------------->*/

int minimumDepth(node* root)
{
	if(!root) return 0;

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	int level=1;
	
	while(!q.empty())
	{
		root=q.front();
		if(root==NULL)
		{
			q.push(NULL);
			level++;
		}
		else
		{
			if(root->left==NULL||root->right==NULL) 
				break;
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
		q.pop();
	}
	return level;
}

void showMap(map<int,int> om)
{
	for(auto i = om.begin();i!=om.end();i++)
		cout<<i->second<<" ";
}

void verticalNodeSum(node* root)
{
	map<int,int> om;
	verticalNodeSumRecur(root,0,om);
	showMap(om);

}

void verticalNodeSumRecur(node* root,int col,map<int,int>&om)
{
	if(root)
	{
		om[col]+=root->data;
		verticalNodeSumRecur(root->left,col-1,om);
		verticalNodeSumRecur(root->right,col+1,om);
	}
}

void zigzagTraversal(node* root)
{
	stack<node*> q; //for even level
	stack<node*> st; //for odd level

	int level = 0;

	q.push(root);

	while(!q.empty()||!st.empty()) //one of them not empty
	{
		node* temp;
		if(level%2==0) //even condition
		{
			while(!q.empty())
			{
				temp = q.top();
				q.pop();
				cout<<temp->data<<" ";
				//push in the stack first left and then right
				if(temp->left)
					st.push(temp->left);
				if(temp->right)
					st.push(temp->right);
			}
		}
		else //odd condition
		{
			while(!st.empty())
			{
				temp = st.top();
				st.pop();
				cout<<temp->data<<" ";
				if(temp->right)
					q.push(temp->right);
				if(temp->left)
					q.push(temp->left);
			}
		}
		level++;
	}
}


node* tree_from_pre_and_in_order(string pre,string in)
{	/*cout<<"\n";*/
	// cout<<pre<<endl;
	// cout<<in<<endl;
	if(in.empty()) return NULL;

	int position = in.find(pre[0]);

	node* root = new node(pre[0]-'0');
	root->left = tree_from_pre_and_in_order(pre.substr(1,position),in.substr(0,position
		));
	root->right = tree_from_pre_and_in_order(pre.substr(position+1),in.substr(position+1));
	return root;
}


node* lca(node* root,int one,int two)
{
	if(!root) return NULL;

	if(root->data==one||root->data==two)
		return root;
	node* l = lca(root->left,one,two);
	node* r = lca(root->right,one,two);

	if(l&&r)
		return root;

	return l?l:r;	
}

void convertMirror(node* root)
{
	if(root)
	{
		convertMirror(root->left);
		convertMirror(root->right);
		swap(root->left,root->right);
	}
}

void all_paths_to_leaves(node* root,string path)
{
	if(!root)
	{
		return ;
	}
	path = path + to_string(root->data)+"->";
	if(!root->left&&!root->right)
	{
		cout<<path.substr(0,path.size()-2)<<endl;
		return;
	}	

	all_paths_to_leaves(root->left,path);
	all_paths_to_leaves(root->right,path);

}

int diameter(node* root)
{  
	/*can be optimized 
		by calculating the height 
		in the same call for diameter*/
	if(!root) return 0;

	int longest = max(diameter(root->left),diameter(root->right));
	longest = max(longest,height(root->left)+height(root->right)+1);
	return longest;
	/*complexity o(n2)*/
}


int height(node* root)
{
    if(!root) return 0;
    return max(height(root->left),height(root->right)) + 1;
}

bool isIdentical(node* root1,node* root2)
{
	if(!root1&&!root2)
	return true;
	
	if(!root1||!root2)
		return false;

	return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}

int leafnodes(node* root)
{
	if(!root) return 0;

	return leafnodes(root->left) + leafnodes(root->right) + (!root->right&&!root->left);
}

node* deeptestNode(node* root)
{
	queue<node*> q;
	// node* temp = root;
	q.push(root);

	while(!q.empty())
	{
		root = q.front();
		q.pop();

		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);

	}
	return root;
}

void reverse_levelorder(node* root)
{
	stack<node*> st; //storing the element
	queue<node*> q; //for level order traversing from right
	q.push(root);

	while(!q.empty())
	{
		root = q.front();
		st.push(root);
		q.pop();

		if(root->right) q.push(root->right);
		if(root->left) q.push(root->left);
	}


	while(!st.empty())
	{
		cout<<st.top()->data<<" ";
		st.pop();
	}

}

int countNode(node* root)
{
	if(!root) return 0;

	return countNode(root->right) + countNode(root->left)+1;
}


int findMax(node* root)
{
	if(!root) return INT_MIN;//return int min when node is null

	int left = findMax(root->left);
	int right = findMax(root->right);
	return max(max(right,left),root->data);
}


void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		root = q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);
	}
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












