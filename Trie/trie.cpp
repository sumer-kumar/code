#include <bits/stdc++.h>
using namespace std;
#define ll long long

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

const int a_size = 26;

struct tnode
{
	tnode* children[a_size];

	bool isEnd;
};
void insert(tnode* root,string key);
void display(tnode* root,string curr="",int level=0);
bool search(tnode* root,string x);


tnode* make_new_tnode()
{
	tnode* t = new tnode();
	t->isEnd = false;
	for(int i=0;i<a_size;i++)
	{
		t->children[i] = NULL;
	}

	return t;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	/*making root*/
	tnode* root = make_new_tnode();

	int n; /*number of words*/
	cin>>n;
	string key;
	/*for insertion*/
	for(int i=0;i<n;i++)
	{
		cin>>key;
		insert(root,key);
	}
	cout<<"input taken"<<endl;
	// display(root);

	cout<<search(root,"sume")<<endl;

	return 0;
}

bool search(tnode* root,string x)
{
	for(int i=0;i<x.size();i++)
	{
		int ind = x[i] - 'a';

		if(root->children[ind]==NULL)
			return false;

		/*traverse to children*/
		root=root->children[ind];
	}

	return (root!=NULL && root->isEnd==true);
}

void display(tnode* root,string curr,int level)
{
	if(root->isEnd)
	{
		cout<<curr<<endl;
	}

	for(int i=0;i<a_size;i++)
	{
		if(root->children[i]!=NULL)
		{
			display(root->children[i],curr+(char)(i+'a'),level+1);
		}
	}
}

void insert(tnode* root,string key)
{
	for(int i=0;i<key.size();i++)
	{	
		int ind = key[i]-'a';
		if(root->children[ind]==NULL) /*insert new node when null*/
		{
			root->children[ind] = make_new_tnode();
		}
		/*traverse*/ 
		root = root->children[ind];
	}
	/*mark end of world true*/
	root->isEnd = true;
}