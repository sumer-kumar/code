#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef priority_queue<int> pq_d;
typedef priority_queue<int,vector<int>,greater<int>> pq_a;

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


void dfs(vi a[],int curr,vector<bool> &visited)
{
	cout<<curr<<endl;
	visited[curr]=true;
	for(int x : a[curr])
	{
		if(!visited[x])
			dfs(a,x,visited);
	}
}

void bfs(vi a[],int V)
{
	queue<int> q;
	vector<bool> visited(V+1,false);
	visited[1]=true;
	q.push(1);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		cout<<curr<<endl;

		for(int x : a[curr])
		{
			if(!visited[x])
			{
				q.push(x);
				visited[x]=true;
			}
		}
	}

}

bool isCyclic(vi a[],int curr,vector<bool> &visited,int parent)
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
	return false;
}

int time = 0;

/*For bridges*/
void bridge(vi a[],int curr,bool visited[],vi &in,vi &low,int parent)
{
	visited[curr]=true;
	in[curr] = time;
	low[curr]=time;

	time++;

	for(int x : a[curr])
	{
		if(x==parent)
			continue;
		if(!visited[x])
		{
			bridge(a,x,visited,in,low,curr);

			// bridge case
			if(low[x] > in[curr])
				cout<<"x"<<" <--> "<<curr<<endl;

			low[curr] = min(low[curr],low[x]);
		}	
		else
		{
			low[curr] = min(low[curr],in[x]);
		}
	}

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	

	bool visited[V+1] = {false};
	// dfs(a,1,visited);
	// bfs(a,V);
	for(int i=1;i<=V;i++)
	{
		if(!visited[i] && isCyclic(a,i,visited,-1)){
			cout<<"true"<<endl;
			break;
		}
	}


	return 0;
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