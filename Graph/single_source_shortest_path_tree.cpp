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
void sssp(vector<int> a[],int V);
void ssspFunc(vector<int> a[],int curr,bool visited[],int paths[],int level=0);



int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	

	sssp(a,V);


	return 0;
}
/*end of main------------------------------------->*/


void sssp(vector<int> a[],int V)
{
	int paths[V+1]={0};

	bool visited[V+1] = {false};

	ssspFunc(a,1,visited,paths,0);

	for(int i=1;i<=V;i++)
	{
		cout<<i<<" : "<<paths[i]<<endl;
	}

}
void ssspFunc(vector<int> a[],int curr,bool visited[],int paths[],int level)
{
	visited[curr] = true;
	paths[curr] = level;

	for(int x : a[curr])
	{
		if(!visited[x])
		{
			ssspFunc(a,x,visited,paths,level+1);
		}
	}
}

void inputGraph(vector<int> a[])
{
	int from,to;
	from =1;
	to = 1;
	while(from>0&&to>0)
	{
		cin>>from>>to;
		if(from>0&&to>0)
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
	for(int i=1;i<=V;i++)
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