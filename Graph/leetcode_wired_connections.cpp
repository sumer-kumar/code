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
void graphGenerator(vector<int> a[],vector<vector<int>>& res,int V);
int wired_connections(vector<vector<int>> a,int V);
int ds_find(vector<int> &parent,int x);
void ds_union(vector<int> &parent, int a,int b);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	

	vector<vector<int>> res;
	graphGenerator(a,res,V);

	cout<<wired_connections(res,V);



	return 0;
}
/*end of main------------------------------------->*/

int wired_connections(vector<vector<int>> a,int V)
{
	/*make set*/
	vector<int> parent(V);
	for(int i=0;i<V;i++)
		parent[i] = i; 
	/*make dsu functions find and union*/

	for(auto x : a)
	{
		ds_union(parent,x[0],x[1]);
	}

	int count = 0;

	for(int i=0;i<V;i++)
	{
		if(parent[i]==i)
			count++;
	}

	for(int i=0;i<V;i++)
	{
		cout<<i<<" : "<<parent[i]<<endl;
	}

	int E = a.size();

	if(E<V-1) 
		return -1;
	cout<<count<<endl;

	return count-1;
}

int ds_find(vector<int> &parent,int x)
{
	if(parent[x] == x)
		return x;
	
	return parent[x] = ds_find(parent,parent[x]);
}

void ds_union(vector<int> &parent, int a,int b)
{
	int x = ds_find(parent,a);
	int y = ds_find(parent,b);

	if(x==y)
		return ;
	parent[x] = y;
}

void graphGenerator(vector<int> a[],vector<vector<int>>& res,int V)
{
	vector<int> cell(2);
	for(int i=0;i<V;i++)
	{
		for(int x : a[i])
		{
			cell[0] = i;
			cell[1] = x;
			res.push_back(cell);
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