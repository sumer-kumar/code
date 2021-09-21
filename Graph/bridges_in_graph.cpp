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

void addEdge(vector<int> a[],int from, int to);
void showGraph(vector<int> a[],int V);
void inputGraph(vector<int> a[]);
void bridges(vector<int> a[],int V);
void dfs(vector<int> a[],int curr,bool visited[],int in[],int low[],
		int &timer,int parent);
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	bridges(a,V);

	return 0;
}
/*end of main------------------------------------->*/

void bridges(vector<int> a[],int V)
{
	bool visited[V] = {false};
	int in[V] = {0};
	int low[V] = {0};
	int timer = 0;

	dfs(a,0,visited,in,low,timer,-1);

}

void dfs(vector<int> a[],int curr,bool visited[],int in[],int low[],
		int &timer,int parent)
{
	visited[curr] = true;
	in[curr] = timer;
	low[curr] = timer;

	timer++;

	for(int x : a[curr])
	{
		if(x == parent) continue;

		if(!visited[x])
		{
			dfs(a,x,visited,in,low,timer,curr);

			if(low[x]>in[curr])
				cout<<"bridge : "<<x<<" <--> "<<curr<<endl;

			low[curr] = min(low[curr],low[x]);
		}
		else
		{
			low[curr] = min(low[curr],in[x]);
		}
	}
}		

void inputGraph(vector<int> a[])
{
	int from,to;
	from =1;
	to = 1;
	while(from>=0&&to>=0)
	{
		cin>>from>>to;
		if(from>=0&&to>=0)
		addEdge(a,from,to);

	}
}

/*for undirected graph*/
void addEdge(vector<int> a[],int from, int to)
{
	a[from].push_back(to);
	a[to].push_back(from);
}

void showGraph(vector<int> a[],int V)
{
	int i=0;
	cout<<"Given Graph :--------> \n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" : ";
		for(int j = 0;j<a[i].size();j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------->"<<endl;

}