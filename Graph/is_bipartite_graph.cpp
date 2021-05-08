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
bool isBipartite(vector<int> a[],int V);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	cout<<(isBipartite(a,V)?"Birpartite":"Not Bipartite")<<endl;

	return 0;
}
/*end of main------------------------------------->*/

bool isBipartite(vector<int> a[],int V)
{
	int source = 1;
	stack<int> st;
	bool visited[V+1] = {false};
	st.push(source);
	
	int color[V+1] = {-1};
	color[source] = 0;

	while(!st.empty())
	{
		int curr = st.top();
		st.pop();
		
		for(int x : a[curr])
		{
			if(visited[x]==false)
			{
				st.push(x);
				visited[curr] = true;
				color[x] = !color[curr];/*give children to opposite color*/
			}
			else if(color[x]==color[curr])
			{
				return false;
			}
		}
	}
	for(int i=1;i<=V;i++)
	{
		cout<<i<<" : "<<(color[i]?"Red":"Blue")<<endl;
	}

	return true;
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