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

/*directed graph so update inputs accordingly*/
void addEdge(vector<int> a[],int from, int to);
void showGraph(vector<int> a[],int V);
void inputGraph(vector<int> a[]);
void kosaraju_algorithm(vector<int> a[],int V);
void dfs(vector<int> a[],int curr,bool visited[],stack<int> & st);
void dfs2(vector<int> a[],int curr,bool visited[],vector<int> & res);


/*start of main----------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	kosaraju_algorithm(a,V);


	return 0;
}
/*end of main------------------------------------->*/

void kosaraju_algorithm(vector<int> a[],int V)
{
	/*first make transpose of the current graph*/
	vector<int> trans[V];

	for(int i=0;i<V;i++)
	{
		for(int j = 0;j<a[i].size();j++)
		{
			trans[a[i][j]].push_back(i);
		}
	}
	cout<<"Transpose graph ";
	showGraph(trans,V);

	/*make dfs call and fill the stack with out time*/	
	stack<int> st;
	bool visited[V] = {false};
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			dfs(a,i,visited,st);
		}
	}
	
	/*now make a dfs call to trans acc to the top of the stack
	  and update show the strongly connected components*/

	/*fill visited with false*/
	for(bool & x: visited)
		x = false;
	vector<int> res;

	while(!st.empty())
	{	res.clear();
		if(!visited[st.top()])
		{
			dfs2(trans,st.top(),visited,res);
		for(int x : res)
		{
			cout<<x<<" ";
		}
		cout<<endl;
		}

		st.pop();
	}

}

/*dfs for finding strongly connected components*/
void dfs2(vector<int> a[],int curr,bool visited[],vector<int> & res)
{
	visited[curr] = true;
	res.push_back(curr);

	for(int x : a[curr])
	{
		if(!visited[x])
		{
			dfs2(a,x,visited,res);
		}
	}
}

/*dfs for collecting out timer*/
void dfs(vector<int> a[],int curr,bool visited[],stack<int> & st)
{
	static int timer = 0;
	visited[curr] = true;
	timer++;

	for(int x : a[curr])
	{
		if(!visited[x])
		{
			dfs(a,x,visited,st);
		}
	}
	timer++;
	st.push(curr);
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