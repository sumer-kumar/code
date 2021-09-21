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


void inputGraph(vector<pair<int,int>> a[]);
void showGraph(vector<pair<int,int>> a[],int V);
void addEdge(vector<pair<int,int>> a[],int from,int to,int weight);

// Kruskals algorithms implementation .................... starts
//make structur to hold edges
struct Edge {

	int from;
	int to;
	int w;

	Edge(int from,int to,int w)
	{
		this->from = from;
		this->to = to;
		this->w = w;
	}
};

//make implementation of dsu
int dsu_find(vi &parent,int x)
{
	if(parent[x]==x)
		return x;
	return parent[x] = dsu_find(parent,parent[x]);
}

void dsu_union(int a,int b,vi &parent)
{
	int p_a = dsu_find(parent,a);
	int p_b = dsu_find(parent,b);

	if(p_a == p_b)
		return;

	parent[p_b] = p_a;
}

bool cmp(Edge &a,Edge &b)
{
	return a.w < b.w;
}

int kruskals(vector<pair<int,int>> a[],int V)
{
	//make a vector of edges
	vector<Edge> edges;
	for(int i=0;i<V;i++)
	{
		for(auto x : a[i])
		{
			edges.push_back(Edge(i,x.first,x.second));
		}
	}

	//sort edges w.r.t weights
	sort(edges.begin(),edges.end(),cmp);

	//initialize dsu
	vi parent(V);
	for(int i=0;i<V;i++)
		parent[i]=i;

	int sum = 0;

	//traverse through every node
	for(int i=0;i<edges.size();i++)
	{
		if(dsu_find(parent,edges[i].from) == dsu_find(parent, edges[i].to))
		continue;

		cout<<edges[i].from<<"<- "<< edges[i].w <<"->"<<edges[i].to<<endl;
		dsu_union(edges[i].from,edges[i].to,parent);
		sum += edges[i].w;
	}

	return sum;

}

//Kruskals algorithm implementation ...................... end






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
    cout<<kruskals(a,V)<<endl;
	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/
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