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
bool isCyclic(vector<int> a[],int V);
bool isCyclicFunc(vector<int> a[],int curr,bool visited[],int parent=-1);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	cout<<isCyclic(a,V);
	return 0;
}
/*end of main------------------------------------->*/

bool isCyclic(vector<int> a[],int V)
{
	bool visited[V] = {false};

	for(int i=0;i<V;i++)
	{
		if(!visited[i]&&isCyclicFunc(a,i,visited)){
					return true;}
	}

	return false;
}
bool isCyclicFunc(vector<int> a[],int curr,bool visited[],int parent)
{

	if(!visited[curr])
	{
		visited[curr] = true;

		for(int x : a[curr])
		{
			if(!visited[x])
			{
				if(isCyclicFunc(a,x,visited,curr))
					return true;
			}
			else if(x!=parent)
			{
				return true;
			}
		}
	}
	return false;
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