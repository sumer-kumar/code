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
bool dfs(vector<pair<int,int>> a[],int curr
	,bool rec[],int sum,int k);
bool path_more_than_k(vector<pair<int,int>> a[],int V,int k);


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

    cout<<path_more_than_k(a,V,60)<<endl;

	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/

bool path_more_than_k(vector<pair<int,int>> a[],int V,int k)
{
	bool rec[V] = {false};

	return dfs(a,0,rec,0,k);
}

bool dfs(vector<pair<int,int>> a[],int curr
	,bool rec[],int sum,int k)
{
	rec[curr] = true;
	if(sum>=k)
		return true;

	for(pair<int,int> x : a[curr])
	{
		int to = x.first;
		int w = x.second;
		if(!rec[to])
		if(dfs(a,to,rec,sum+w,k)==true)
			return true;
	}

	rec[curr] = false;
	return false;
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