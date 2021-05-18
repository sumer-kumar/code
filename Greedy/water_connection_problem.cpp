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

void dfs(vector<pair<int,int>> a[],int curr,bool visited[],int &minDia,int & last)
{
	visited[curr] = true;
	last = curr;
	
	for(auto x : a[curr])
	{
		if(!visited[x.first])
		{	
			minDia = min(minDia,x.second);
			dfs(a,x.first,visited,minDia,last);
		}
	}
}


void water_prb(int n,int p,vector<int>start ,vector<int> end,vector<int> dia)
{
	/*make a weighted directed graph*/
	vector<pair<int,int>> a[p+1];  /*to and weight*/

	for(int i=0;i<n;i++)
	{
		/*directed graph*/
		a[start[i]].push_back({end[i],dia[i]});
	}

	int V = p;
	for(int i=1;i<=V;i++)
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
	vector<int> endpoints;

	for(int i=1;i<=p;i++)
	{
		if(a[i].size()==0)/*end points*/
		{
			endpoints.push_back(i);
		}
	}

	/*now make graph undirected*/
	for(int i=0;i<n;i++)
	{
		a[end[i]].push_back({start[i],dia[i]});
	}


	bool visited[p+1] = {false};
	int count = endpoints.size();
	vector<vector<int>> res;

	vector<int> t ;
	t.push_back(count);
	res.push_back(t);
	/*run dfs taking one element at once in endpoints*/
	for(int i=0;i<endpoints.size();i++)
	{

		int minDia = INT_MAX;
		int last;
		dfs(a,endpoints[i],visited,minDia,last);
		vector<int> temp(3);
		temp[0] = last;
		temp[1] = endpoints[i];
		temp[2] = minDia;

		if(minDia!=INT_MAX)
		res.push_back(temp);
	}

	for(auto x : res)
	{
		for(int p : x)
			cout<<p<<" ";
		cout<<endl;
	}

}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {4,3,2};	
    vector<int> b = {3,1,5};	
    vector<int> c = {96,48,6};

    int n = 3;
    int p = 6;	

    water_prb(n,p,a,b,c);

	return 0;
}