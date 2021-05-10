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

#define root -1


void addEdge(vector<int> a[],int from, int to);
void showGraph(vector<int> a[],int V);
void inputGraph(vector<int> a[]);
void articulation_point(vector<int> a[],int V);
void articulation_point_until(vector<int> a[],int curr,int par,
	bool visited[],int in[],int low[],set<int> &s);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);

	articulation_point(a,V);
	return 0;
}
/*end of main------------------------------------->*/


void articulation_point(vector<int> a[],int V)
{
	bool visited[V] = {false};
	int in[V]={0};
	int low[V]={0};
	set<int> s;

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{	/*root=-1*/
			articulation_point_until(a,i,root,visited,in,low,s);
		}
	}

	for(auto i = s.begin();i!=s.end();i++)
		cout<<*i<<" ";
}
void articulation_point_until(vector<int> a[],int curr,int par,
	bool visited[],int in[],int low[],set<int> & s)
{

	static int timer = 1;
	visited[curr] = true;
	in[curr] = timer;
	low[curr] = timer;
	timer++;

	int childs = 0;

	/*traversing through the connected nodes of curr node*/
	for(int x : a[curr])
	{


		/*if connects to parent do nothing*/
		if(x == par) continue;

		/*backedge condtion*/
		if(visited[x])
		{	
			/*update low of curr node */
			low[curr] = min(low[curr],in[x]);
		}	
		else /*not visited*/
		{
			/*first make a dfs call */
			articulation_point_until(a,x,curr,visited,in,low,s);

			/*check if its a articulation point and not a root*/
			if(low[x]>=in[curr] && par!=root)
			{
				// cout<<curr<<endl;
				s.insert(curr);
			}

			low[curr] = min(low[curr],low[x]);
			childs++;
		}

	}
	if(curr==root && childs > 1 )
		cout<<curr<<" "<<childs<<endl;
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