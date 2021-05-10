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

int island_count(vector<vector<char>> &a);
void dfs(vector<vector<char>> &a,vector<vector<bool>>& visited,int i,int j);



int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int row,col;
	cin>>row>>col;

	vector<vector<char>> a(row,vector<char>(col));

	/*input grid*/	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}	

	cout<<island_count(a);

	return 0;
}

int island_count(vector<vector<char>> &a)
{
	int row = a.size();
	int col = a[0].size();

	vector<vector<bool>> visited(row,vector<bool>(col,false));
	int count = 0;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(!visited[i][j]&&a[i][j]=='1')
			{
				count++;
				dfs(a,visited,i,j);
			}
		}
	}
	return count;
}

void dfs(vector<vector<char>> &a,vector<vector<bool>>& visited,int i,int j)
{
	int row = a.size();
	int col = a[0].size();

	/*check validations*/
	if(i<0 || i>=row || j<0 || j>= col ) 
		return ;

	/*if already visited*/
	if(visited[i][j]==true)
		return ;

	/*if path is blocked*/
	if(a[i][j]=='0')
		return ;

	visited[i][j] = true;

	dfs(a,visited,i+1,j );

	dfs(a,visited,i-1,j );
	
	dfs(a,visited,i ,j+1);
	
	dfs(a,visited,i ,j-1);
	
	dfs(a,visited,i+1,j+1);
	
	dfs(a,visited,i-1,j-1);
	
	dfs(a,visited,i-1,j+1);
	
	dfs(a,visited,i+1,j-1);

}