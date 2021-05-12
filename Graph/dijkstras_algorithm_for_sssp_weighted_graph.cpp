#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 999

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
void graph_converter(vector<pair<int,int>> a[],vector<vector<int>> res[],int V);
void dijkstras(vector<vector<int>> a[],int V,int source);


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

    dijkstras(res,V,0);

	return 0;
}

/*end of main ----------------------------------->*/

void dijkstras(vector<vector<int>> a[],int V,int source)
{
	vector<int> dist(V,INF);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;/*weight curr_node*/

	/*make source element 0*/
	dist[source] = 0;
	
	/*push source with dist 0 in priority queue*/
	pq.push({0,source});

	while(!pq.empty())
	{
		pair<int,int> curr = pq.top();
		pq.pop();

		int w = curr.first;
		int to = curr.second;

		/*explore the node*/
		for(int i = 0;i<a[to].size();i++)
		{	
			int x_weight = a[to][i][1];
			int x_node = a[to][i][0];

			if( w + x_weight < dist[x_node])
			{
				dist[x_node] = w + x_weight;

				if(dist[x_node]!=INF)
				pq.push({dist[x_node],x_node});
			}
		}

		for(auto x : dist)
			cout<<x<<" ";
		cout<<endl;
	}

	cout<<"minimum distance of source : "<<source<<endl;
	for(int i=0;i<V;i++)
		{
			cout<<i<<" : "<<dist[i]<<endl;
		}
}


/*other functions-------------------------------->*/

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
/*
	cout<<"converted graph "<<endl;

	for(int i=0;i<V;i++)
	{	cout<<i<<" : "<<endl;
		for(auto x : res[i])
		{
			for(int p : x)
				cout<<"\t"<<p<<" ";
			cout<<endl;
		}
		cout<<endl;
	}*/
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