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

struct tnode{
	tnode* children[a_size];
	bool isEnd;
	vector<int> arr;

	tnode()
	{
		for(int i=0;i<a_size;i++)
		{
			children[i] = NULL;
		}
		isEnd = false;
	}
};

void insert(tnode* root,string x,int index)
{
	int j = x[0]-'a';
	if(root->children[j]==NULL)
		root->children[j] = new tnode();
	root = root->children[j];

	for(int i = 1;i<x.size();i++)
	{
		j = x[i]-'a';
		if(root->children[j]==NULL)
			root->children[j] = new tnode();

		root->arr.push_back(index);
		root = root->children[j];
	}
	root->arr.push_back(index);
	root->isEnd = true;
}

void display(tnode* root,string curr="",int level = 0)
{
	if(root->isEnd==true)
	{
		cout<<curr<<endl;
	}
	
	for(int i=0;i<a_size;i++)
	{
		if(root->children[i]!=NULL)
		{
			display(root->children[i],curr + (char)(i+'a'),level+1);
		}
	}
}

void search(tnode* root,vector<vector<int>>& res,string sent)
{
	int j;
	for(int i = 0;i<sent.size();i++)
	{
		j = sent[i] - 'a';
		if(root->children[j]==NULL)
			return ;
		root = root->children[j];
		res.push_back(root->arr);
	}
}

void phone(string a[],int n,string sent)
{
	tnode* root = new tnode();
	for(int i=0;i<n;i++)
	{
		insert(root,a[i],i);
	}

	display(root);

	vector<vector<int>> res;

	search(root,res,sent);

	vector<vector<string>> ans;

	for(auto x : res)
	{	vector<string> temp;
		for(int p : x)
		{
			temp.push_back(a[p]);
		}
		ans.push_back(temp);
	}

	for(int i = 1;i<= sent.size()-res.size();i++)
	{
		vector<string> t;
		t.push_back("0");
		ans.push_back(t);
	}

	for(auto x : ans)
	{
		for(string p : x)
			cout<<p<<" " ;
		cout<<endl;
	}

}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string a[] = {"geeiki", "geekss", "geeksf"};
	int n = 3;
	string sent = "geekps";
	phone(a,n,sent);

	return 0;
}