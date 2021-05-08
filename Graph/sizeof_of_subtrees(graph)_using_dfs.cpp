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
void sizeof_subtrees(vector<int> a[],int V,int root=0);
int dfs(vector<int> a[],int curr,bool visited[],int size_arr[]);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	sizeof_subtrees(a,V);

	return 0;
}
/*end of main------------------------------------->*/


void sizeof_subtrees(vector<int> a[],int V,int root)
{
	bool visited[V] = {false};
	int size_arr[V] = {0};

	dfs(a,root,visited,size_arr);
	int i=0;
	cout<<"Size of Subtrees from root : "<<root<<endl;
	for(int x : size_arr)
		cout<<i++<<" : "<<x<<endl;

}

int dfs(vector<int> a[],int curr,bool visited[],int size_arr[])
{
	visited[curr] = true;
	int curr_size = 1;

	for(int x : a[curr])
	{
		if(!visited[x])
		{	
			curr_size += dfs(a,x,visited,size_arr);
		}

	}

	size_arr[curr] = curr_size;
	return curr_size;
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