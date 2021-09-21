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
vector<int> bfsFunc(vector<int> a[],int V,int source);
void bfs(vector<int> a[],int V,int source);
vector<int> dfsFunc(vector<int> a[],int V,int source);
void dfs(vector<int> a[],int V,int source);

/*Main--------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	bfs(a,V,2);
	dfs(a,V,1);

	return 0;
}
/*end main------------------------------------>*/

void dfs(vector<int> a[],int V,int source)
{
	vector<int> res = dfsFunc(a,V,source);
	cout<<"dfs from source : "<<source<<" : ";
	for(int x : res)
		cout<<x<<" ";
	cout<<endl;
}

vector<int> dfsFunc(vector<int> a[],int V,int source)
{
	stack<int> st;
	bool visited[V+1] = {false};
	st.push(source);
	// visited[source] = true;
	vector<int> res;

	/*st :    */
	/*curr : 3 */
	/*res :  1 2 5 3 */

	/*visited : 1 2 3 4 5 */
	/*          t t t f t */

	while(!st.empty())
	{
		int curr = st.top();
		st.pop();
		

		if(visited[curr]==false)
		{
			res.push_back(curr);
			visited[curr] = true;	
		}

		for(int x : a[curr])
		{
			if(visited[x]==false)
			{
				st.push(x);
			}
		}
	}
	return res;
}

void bfs(vector<int> a[],int V,int source)
{
	vector<int> res = bfsFunc(a,V,source);
	cout<<"bfs from source : "<<source<<" : ";
	for(int x : res)
		cout<<x<<" ";
	cout<<endl;
}

vector<int> bfsFunc(vector<int> a[],int V,int source)
{
	//first push source vertex into queue
	queue<int> q;
	q.push(source);

	bool visited[V+1] = {false};
	visited[source] = true;//marking visited for source node

	vector<int> res;
	while(!q.empty())
	{   
		int curr = q.front();
		q.pop();
		res.push_back(curr);

		for(int x : a[curr])
		{
			/*if not visited before*/
			if(visited[x]==false)
			{
				q.push(x);
				visited[x]=true;
			}
		}
	}
	return res;
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