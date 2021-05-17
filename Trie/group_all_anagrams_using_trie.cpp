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

#define a_size 26

struct tnode
{
	tnode* children[a_size];
	bool isEnd;
	vector<int> arr;
};

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

void insert(tnode* root,string x,int curr)
{
	
	for(int i = 0;i<x.size();i++)
	{
		int index = x[i] - 'a';
		if(root->children[index]==NULL)
			root->children[index] = make_new_tnode();

		root = root->children[index];
	}
	(root->arr).push_back(curr);
	root->isEnd = true;
}

void search(tnode* root,vector<vector<int>>& res)
{
	if(root->isEnd)
	{
		res.push_back(root->arr);
	}

	for(int i=0;i<a_size;i++)
	{
		if(root->children[i]!=NULL)
		{
			search(root->children[i],res);
		}
	}
}

void display(tnode* root,string curr="",int level=0)
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

void anangrams(string a[],int n)
{
	tnode* root = new tnode();
	vector<string> ca(a,a+n);

	for(int i=n-1;i>=0;i--)
	{	
		sort(ca[i].begin(),ca[i].end());
		insert(root,ca[i],i);
	}

	vector<vector<int>> res;

	search(root,res);

	sort(res.begin(),res.end());/*sort with first element*/

	for(int i=0;i<res.size();i++)
	{
		reverse(res[i].begin(),res[i].end());/*largest element is at last*/
	}

	vector<vector<string>> ans;

	for(auto x : res)
	{
		vector<string> temp;
		for(int p : x)
		{
			temp.push_back(a[p]);
		}
		ans.push_back(temp);
	}

	for(auto x : ans)
	{
		for(string p : x)
			cout<<p<<" ";
		cout<<endl;
	}

}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string a[] = {"act","god","cat","dog","tac"};
	int size = 5; 	

	anangrams(a,size);
	// cout<<"bang"<<endl;

	return 0;
}











