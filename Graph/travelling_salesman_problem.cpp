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

int minSum = INT_MAX;
void inputGraph(vector<pair<int,int>> a[]);
void showGraph(vector<pair<int,int>> a[],int V);
void addEdge(vector<pair<int,int>> a[],int from,int to,int weight);
int travelling_salesman_problem(vector<pair<int,int>> a[],int V);
void dfs(vector<pair<int,int>> a[],int curr,bool rec[],int V
		,int level,int sum,int source);

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

    travelling_salesman_problem(a,V);

	return 0;
}

/*end of main ----------------------------------->*/




/*other functions-------------------------------->*/

int i = 0;
int travelling_salesman_problem(vector<pair<int,int>> a[],int V)
{
	bool rec[V] = {false};

	for(int i=0;i<V;i++)
		dfs(a,i,rec,V,0,0,i);

	cout<<minSum<<endl;

 	return 0;
}

void dfs(vector<pair<int,int>> a[],int curr,bool rec[],int V
		,int level,int sum,int source)
{
	
	if(level==V)
	{	
		minSum = min(minSum,sum);
		return ;	
	}
	rec[curr] = true;

	for(pair<int,int> x : a[curr]) 
	{
		// cout<<i++<<" ";
		if(!rec[x.first] || (x.first == source && level==V-1))
		{	
			// cout<<curr<<"-->"<<x.first<<"\nsum : "<<sum<<"\nweight :"<<x.second<<endl;
			// cout<<"curr level : "<<level<<endl;
			// cout<<"min sum : "<<minSum<<"\n\n"<<endl;

			dfs(a,x.first,rec,V,level+1,sum+x.second,source);
		}
	}
	rec[curr] = false;
	return ;
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

		cout<<(i+1)<<" : ";
		for(auto x : a[i])
		{
			str += "(" + to_string(x.first+1) + "," 
					+ to_string(x.second) +")"+ "-";
		}
		cout<<str.substr(0,str.size()-1)<<endl;
	}

	cout<<"--------------------->\n";
}