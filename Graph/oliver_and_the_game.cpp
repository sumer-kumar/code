#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

using namespace std;
#define ll long long

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

void dfs(vector<int> a[],int curr,bool visited[],int in[],int out[]);

int timer;

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V;
    cin>>V;
    /*1 base indexing*/
    vector<int> a[V+1];
    for(int i=0;i<V-1;i++)
    {
    	int from,to;
    	cin>>from>>to;
    	a[from].push_back(to);
    	a[to].push_back(from);/*undirected graph*/
    }

    int qrs;
    cin>>qrs;
    bool visited[V+1] = {false};
	timer = 0;
	int in[V+1];
	int out[V+1];

    dfs(a,1,visited,in,out);

    while(qrs--)
    {	
	  	int x,to,from;
    	cin>>x>>to>>from;

    	if(x==1)
    		swap(to,from);

    	if(in[to]<=in[from] && out[from]<=out[to])
    		cout<<"YES"<<endl;

    	else
    		cout<<"NO"<<endl;
    }

	return 0;
}

void dfs(vector<int> a[],int curr,bool visited[],int in[],int out[])
{
	timer++;
	in[curr] = timer;
	visited[curr] = true;

	for(int x : a[curr])
	{
		if(!visited[x])
		{
			dfs(a,x,visited,in,out);
		}
	}

	timer++;
	out[curr] = timer; 
}