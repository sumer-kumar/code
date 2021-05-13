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
void bellmanFord(vector<vector<int>> a,int V);


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

    vector<vector<int>> res(V,vector<int> (V,-1));

    /*fill diagonal with zero*/
    for(int i=0;i<V;i++)
    	res[i][i] = 0;

    for(int i=0;i<V;i++)
    {
    	for(auto x : a[i])
    	{
    		res[i][x.first] = x.second;
    	}
    }

    for(auto x : res)
    {
    	for(int p : x)
    		cout<<p<<" ";
    	cout<<"\n";

    }

    bellmanFord(res,V);

	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/

void bellmanFord(vector<vector<int>> a,int V)
{
	for(int k =0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				/*below conditions are because here infinity is replaced by -1*/
				if(a[i][j]==-1)/*is infinity*/
				{
					if(a[i][k]!=-1 && a[k][j]!=-1)
						a[i][j] = a[i][k] + a[k][j]; 
				}
				else
				{
					if(a[i][k]!=-1 && a[k][j]!=-1)
						a[i][j] = min(a[i][j],a[i][k] + a[k][j]); 
				}
			}
		}
	}
	cout<<"\n\n";
	for(auto x : a)
    {
    	for(int p : x)
    		cout<<p<<" ";
    	cout<<"\n";

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
	// a[to].push_back({from,weight});
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