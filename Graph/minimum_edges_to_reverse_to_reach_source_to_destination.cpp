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


void inputGraph(vector<pair<int,int>> a[]);
void showGraph(vector<pair<int,int>> a[],int V);
void addEdge(vector<pair<int,int>> a[],int from,int to,int weight);
int minimum_edges_to_reverse(vector<pair<int,int>> a[],int V,int src,int dest);


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

    cout<<minimum_edges_to_reverse(a,V,0,4)<<endl;

	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/

int minimum_edges_to_reverse(vector<pair<int,int>> a[],int V,int src,int dest)
{
	/*first reverse the the edges and add weight 1*/
	for(int i=0;i<V;i++)
	{
		for(auto x : a[i])
		{
			int from = i;
			int to = x.first;

			a[to].push_back({i,1});
		}
	}

	showGraph(a,V);

	int INF = 1000000;

	/*find shortest path to all the edges*/
	vector<int> path(V,INF);
	path[src] = 0;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	pq.push({0,src}); /*first = weight and second = node*/

	while(!pq.empty())
	{
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		/*explore the node*/
		for(auto x : a[u])
		{
			int _u = x.first;
			int _w = x.second;

			if(w + _w < path[_u])
			{
				path[_u] = w + _w;

				pq.push({path[_u],_u});
			}
		}
	}

	// for(int x : path)
	// 	cout<<x<<" ";

	return path[dest];	
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
	// a[to].push_back({from,1});
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