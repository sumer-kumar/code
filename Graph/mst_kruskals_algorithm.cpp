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

struct Edge {
	int from;
	int to;
	int w;

	Edge()
	{
		from = to = w =0;
	}

	Edge(int f,int t,int weight)
	{
		from = f;
		to = t;
		w = weight;
	}

};


void inputGraph(vector<pair<int,int>> a[]);
void showGraph(vector<pair<int,int>> a[],int V);
void addEdge(vector<pair<int,int>> a[],int from,int to,int weight);
void graph_converter(vector<pair<int,int>> a[],vector<vector<int>> res[],int V);
bool cmp(Edge a,Edge b);
int dsu_find(int parent[],int x);
void dsu_union(int parent[],int a,int b);
int mst_kruskal(vector<vector<int>> a[],int V);

/*start of main -------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V,E;
    cin>>V>>E;

    vector<pair<int,int>> a[V]; /*edge and data*/
    inputGraph(a);
    showGraph(a,V);

    vector<vector<int>> res[V];

    graph_converter(a,res,V);

    cout<<mst_kruskal(res,V)<<endl;

	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/

int mst_kruskal(vector<vector<int>> a[],int V)
{
	vector<Edge> edge;

	/*make set*/
	int parent[V];
	for(int i=0;i<V;i++)
		parent[i] = i;
	int k = 0;

	/*add edges of given graph into edges[]*/
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			Edge temp = Edge(i,a[i][j][0],a[i][j][1]);
			edge.push_back(temp);

		}
	}

	sort(edge.begin(),edge.end(),cmp);

	int sum =0;

	for(Edge x : edge)
	{
		if(dsu_find(parent,x.from)==dsu_find(parent,x.to))
		{
			continue;
		}
		else
		{
			cout<<x.from<<"<->"<<x.to<<" : "<<x.w<<endl;
			sum+=x.w;
			dsu_union(parent,x.from,x.to);
		}

	}

	return sum;
}

int dsu_find(int parent[],int x)
{
	if(parent[x]==x)
		return x;
	return parent[x] = dsu_find(parent,parent[x]);
}

void dsu_union(int parent[],int a,int b)
{
	int x = dsu_find(parent,a);
	int y = dsu_find(parent,b);

	if( x==y )
		return ;
	parent[x] = y;
}

bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}

void graph_converter(vector<pair<int,int>> a[],vector<vector<int>> res[],int V)
{
	vector<int> block(2);
	for(int i=0;i<V;i++)
	{
		for(auto x : a[i])
		{
			block[0] = x.first;
			block[1] = x.second;

			res[i].push_back(block);
		}
	}

	cout<<"converted graph "<<endl;

	for(int i=0;i<V;i++)
	{	cout<<i<<" : "<<endl;
		for(auto x : res[i])
		{
			for(int p : x)
				cout<<p<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}



void inputGraph(vector<pair<int,int>> a[])
{
	int from,to,weight;
	from = to = weight = 1;

	while(from >=0 && to >= 0 )
	{
		cin>>from>>to>>weight;

		if(from >=0 && to >= 0)
			addEdge(a,from,to,weight);
	}

}

void addEdge(vector<pair<int,int>> a[],int from,int to,int weight)
{
	a[from].push_back({to,weight});

	/*for undirected*/
	a[to].push_back({from,weight});
}

void showGraph(vector<pair<int,int>> a[],int V)
{
	cout<<"Note : first element in bracket is edge second is weight\n";
	cout<<"Given Graph :--------> \n";

	for(int i=0;i<V;i++)
	{
		string str = "";

		cout<<i<<" : ";
		for(auto x : a[i])
		{
			str += "(" + to_string(x.first) + "," 
					+ to_string(x.second) +")"+ "-";
		}
		cout<<str.substr(0,str.size()-1)<<endl;
	}

	cout<<"--------------------->\n";
}