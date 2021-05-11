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
void tarjan_algorithm(vector<int> a[],int V);
void dfs(vector<int> a[],int curr,bool visited[]
		,bool on_st[],stack<int>&st,int in[],int low[]);

/*for directed graph modify inputs accordingly*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	

	tarjan_algorithm(a,V);
	return 0;
}
/*end of main------------------------------------->*/

void tarjan_algorithm(vector<int> a[],int V)
{
	bool visited[V] = {false};
	bool on_st[V] = {false};
	
	int in[V] = {0};
	int low[V] = {0};

	stack<int> st;

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		dfs(a,i,visited,on_st,st,in,low);
	}
}

void dfs(vector<int> a[],int curr,bool visited[]
		,bool on_st[],stack<int>&st,int in[],int low[])
{
	static int timer = 1;
	visited[curr] = true;
	st.push(curr);
	on_st[curr] = true;
	in[curr] = low[curr] = timer++;

	for(int x : a[curr])
	{
		if(visited[x] && on_st[x])
		{	
			low[curr] = min(low[curr],in[x]);
		}
		else if (!visited[x])
		{
			dfs(a,x,visited,on_st,st,in,low);

			if(on_st[x])
			low[curr] = min(low[curr],low[x]);
		}	
	}
	static int cnt = 0;

	if(in[curr]==low[curr])
	{	
		cnt++;
		cout<<"stack size : "<<st.size()<<endl;
		while(true)
		{
			int u = st.top();
			st.pop();
			on_st[u] = false;

			cout<<u<<" ";

			if(curr == u)
				break; 
		}
		cout<<"\n";
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
	// a[to].push_back(from);
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