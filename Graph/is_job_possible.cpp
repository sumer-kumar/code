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
bool canFinish(vector<int> a[],int V);
bool isCyclic(vector<int> a[],int curr,vector<bool>&visited,vector<bool>& rec);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int V,E;/*number of vertices and edges resp.*/
	cin>>V>>E;
	vector<int> a[V+1];
	inputGraph(a);
	showGraph(a,V);	
	vector<bool> visited(V,false);
	vector<bool> rec(V,false);
	cout<<isCyclic(a,0,visited,rec);

	return 0;
}
/*end of main------------------------------------->*/


bool isCyclic(vector<int> a[],int curr,vector<bool>&visited,vector<bool>& rec)
{
    visited[curr] = true;
    rec[curr] = true;
    
    for(int x : a[curr])
    {
        if(!visited[x]&&isCyclic(a,x,visited,rec)==true)
        {
        	return true;
        }
        else if(rec[x]==true)
        	return true;

    }
    rec[curr] = false;
    return false;
}
    
bool canFinish(vector<int> a[],int V) 
{    
    
    vector<bool> visited(V,false);
    //call dfs to detech cycle 
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            // if(isCyclic(a,i,visited,)==true)
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
	// a[to].push_back(from);
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