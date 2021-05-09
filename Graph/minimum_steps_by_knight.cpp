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
int minimumStepsByKnight(int x1,int y1,int x2,int y2,int n);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// int V,E;/*number of vertices and edges resp.*/
	// cin>>V>>E;
	// vector<int> a[V+1];
	// inputGraph(a);
	// showGraph(a,V);	

    cout<<minimumStepsByKnight(4,5,1,1,6)<<endl;

	return 0;
}
/*end of main------------------------------------->*/

int minimumStepsByKnight(int x1,int y1,int x2,int y2,int n)
{
	if(x1==x2&&y1==y2) return 0;

	int visited[n+1][n+1] = {0};
	
	queue<pair<int,int>> q; /*x and y*/
	
	pair<int,int> curr = {x1,y1};

	q.push(curr);

	while(!q.empty())
	{
		curr = q.front();
		q.pop();

		int i = curr.first;
		int j = curr.second;

		if(visited[x2][y2]!=0)
		{
			break;
		}

		/*fill carefully*/

		/*up left i-2 j-1*/
		if( i-2>0 && j-1>0 && visited[i-2][j-1]==0)
		{	
			visited[i-2][j-1] = visited[i][j]+1;
			q.push({i-2,j-1});
		}

		/*up right   i-2 j+1*/
		if( i-2>0 && j+1<=n && visited[i-2][j+1]==0)
		{	
			visited[i-2][j+1] = visited[i][j]+1;
			q.push({i-2,j+1});
		}


		/*right up   i-1 j+2*/
		if( i-1>0 && j+2<=n && visited[i-1][j+2]==0)
		{	
			visited[i-1][j+2] = visited[i][j]+1;
			q.push({i-1,j+2});
		}


		/*right down i+1 j+2*/
		if( i+1<=n && j+2<=n && visited[i+1][j+2]==0)
		{	
			visited[i+1][j+2] = visited[i][j]+1;
			q.push({i+1,j+2});
		}


		/*down right i+2 j+1*/
		if( i+2<=n && j+1<=n && visited[i+2][j+1]==0)
		{	
			visited[i+2][j+1] = visited[i][j]+1;
			q.push({i+2,j+1});
		}


		/*down left  i+2 j-1*/
		if( i+2<=n && j-1>0 && visited[i+2][j-1]==0)
		{	
			visited[i+2][j-1] = visited[i][j]+1;
			q.push({i+2,j-1});
		}


		/*left down  i+1 j-2*/
		if( i+1<=n && j-2>0 && visited[i+1][j-2]==0)
		{	
			visited[i+1][j-2] = visited[i][j]+1;
			q.push({i+1,j-2});
		}


		/*left up 	 i-1 j-2*/
		if( i-1>0 && j-2>0 && visited[i-1][j-2]==0)
		{	
			visited[i-1][j-2] = visited[i][j]+1;
			q.push({i-1,j-2});
		}
	}	
	return visited[x2][y2];
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