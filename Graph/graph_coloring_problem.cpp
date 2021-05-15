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
int chromatixNumber(vector<int> a[],int V);
bool m_color_problem(vector<int> a[],int V,int m);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	

	// cout<<m_color_problem(a,V,3);

	cout<<chromatixNumber(a,V)<<endl;

	return 0;
}
/*end of main------------------------------------->*/

int chromatixNumber(vector<int> a[],int V)
{
	/*make array to store the colors of the node*/
	int res[V];
	memset(res,-1,sizeof(res));
	/*assign 0 color to first node*/
	res[0] = 0;

	/*array of colors*/
	bool used[V];


	int ans = INT_MIN;

	/*now pick a node
	  note the color of adjacent nodes
	  give the color different from the adjacent node 
	  do this for all the nodes except first node*/

	for(int i=1;i<V;i++)
	{
		/*fill all colors with false*/
		memset(used,false,sizeof(used));

		/*check the color of adjacent node and mark the used colors*/
		for(int x : a[i])
		{
			if(res[x]!=-1)
			{
				used[res[x]] = true;
			}
		}

		int curr;

		/*check the color which is unused*/
		for(int j = 0;j<V;j++)
		{
			if(used[j]==false)
			{
				res[i] = j;
				ans = max(ans,j);
				break;
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		cout<<i<<"-->"<<res[i]<<endl;
	}

	return ans+1;
}

bool m_color_problem(vector<int> a[],int V,int m)
{
	/*make array to store the colors of the node*/
	int res[V];
	memset(res,-1,sizeof(res));
	/*assign 0 color to first node*/
	res[0] = 0;

	/*array of colors*/
	bool used[m];


	int ans = INT_MIN;

	/*now pick a node
	  note the color of adjacent nodes
	  give the color different from the adjacent node 
	  do this for all the nodes except first node*/

	for(int i=1;i<V;i++)
	{
		/*fill all colors with false*/
		memset(used,false,sizeof(used));

		/*check the color of adjacent node and mark the used colors*/
		for(int x : a[i])
		{
			if(res[x]!=-1)
			{
				used[res[x]] = true;
			}
		}

		/*check the color which is unused*/

		bool isAvailable = false;

		for(int j = 0;j<m;j++)
		{
			if(used[j]==false)
			{
				isAvailable = true;
				res[i] = j;
				break;
			}
		}
		if(!isAvailable)
		{
			return false;
		}
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