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

struct tnode
{
	tnode* one ;
	tnode* zero;
	bool isEnd;
	int count;
	tnode()
	{
		one = NULL;
		zero = NULL;

		isEnd = false;
		count = 0;
	}
};

void insert(tnode* root,int a[],int size)
{

	for(int i=0;i<size;i++)
	{
		if(a[i]==0)
		{
			if(root->zero==NULL)
				root->zero = new tnode();
			root = root->zero;
		}
		else
		{
			if(root->one==NULL)
				root->one = new tnode();
			root = root->one;
		}
		root->count += 1;
	}
	root->isEnd = true;
}

bool isUnique(tnode* root,int *a,int size)
{
	for(int i=0;i<size && root!=NULL;i++)
	{
		if(a[i]==0)
		{
			root= root->zero;
		}
		else
		{	
			root = root->one;
		}

		if(root->count==1)
		{
			return true;
		}
		if(root->isEnd)
			break;
	}

	return false;
}

void print_unique()
{
	int M[3][4] = {{1, 1 ,0, 1},{1, 0 ,0, 1},{1, 1 ,0 ,1}};

	tnode* root = new tnode();
	for(int i=0;i<3;i++)
	{
		insert(root,M[i],3);
	}
	vector<vector<int>> res;
	for(int i=0;i<3;i++)
	{
		if(isUnique(root,M[i],3))
		{
			vector<int> temp(M[i],M[i]+4);
			res.push_back(temp);
		}
	}
	for(auto x : res)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}
}



int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	print_unique();

	return 0;
}