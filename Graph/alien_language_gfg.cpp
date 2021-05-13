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

string alien(string dict[],int size,int maxChar);
void dfs(unordered_map<char,vector<char>>& um,char curr
	,unordered_map<char,bool>& visited,stack<char> &st);
void addEdges(unordered_map<char,vector<char>>& um,string first,string second);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string dict[] = {"baa","abcd","abca","cab","cad"};
    int n = 5;
    int k = 4;

    cout<<alien(dict,n,k)<<endl;
	
	return 0;
}

string alien(string dict[],int size,int maxChar)
{
	/*make graph adj list*/
	unordered_map<char,vector<char>> um;

	/*add edges in the graph*/
	for(int i=1;i<size;i++)
	{
		addEdges(um,dict[i-1],dict[i]);
	}


	// uncomment to print the graph 
	for(auto x = um.begin();x!=um.end();x++)
	{
		cout<<x->first<<" : ";
		for(char p : x->second)
		{
			cout<<p<<" - ";
		}
		cout<<endl;
	}

	/*do topological sort and return the string*/
	unordered_map<char,bool> visited;

	/*fill the visited map with false*/
	for(auto x = um.begin();x!=um.end();x++)
	{
		visited[x->first] = false;
	}

	stack<char> st;

	for(auto x = um.begin();x!=um.end();x++)
	{
		if(!visited[x->first])
		{
			dfs(um,x->first,visited,st);
		}
	}

	string res = "";
	while(!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}
	return res;
}

void dfs(unordered_map<char,vector<char>>& um,char curr
	,unordered_map<char,bool>& visited,stack<char> &st)
{
	visited[curr] = true;

	for(char x : um[curr])
	{
		if(!visited[x])
		{
			dfs(um,x,visited,st);
		}
	}

	st.push(curr);
}

void addEdges(unordered_map<char,vector<char>>& um,string first,string second)
{
	for(int i=0;i<first.size()&&i<second.size();i++)
	{
		if(first[i]!=second[i])
		{
			um[first[i]].push_back(second[i]);
			// cout<<first[i]<<"-->"<<second[i]<<endl;
			return ;
		}
	}
}


// void func()
// {
// 	vector<vector<int>> g(k);
// 	for(int i=0;i<n-1;i++)
// 	{
// 		string w1 = dict[i];
// 		string w2 = dicr[i+1];

// 		for(int j=0;j<min(w1.length(),w2.length()))
// 		{
// 			if(w1[j]!=w2[j])
// 			{
// 				g[w1[j]-'a'].push_back(w2[j]-'a');
// 				break;
// 			}
// 		}
// 	}
// 	vector<int> vis(k,0);
// 	string ans = "";
// 	for(int i=0;i<k;i++)
// 	{
// 		if(!vis[i])
// 		{
// 			dfs(i,g,vis,ans);
// 		}
// 	}
// 	return ans;
// }

// void dfs(int src, vector<vector<int>> &g,vector<int>&vis, string &ans)
// {
// 	vis[src] = 1;
// 	for(auto x : g[src])
// 	{
// 		if(!vis[x])
// 		{
// 			dfs(x,g,vis,ans);
// 		}
// 	}
// 	char ch = src + 'a';
// 	ans = ch + ans;
// }