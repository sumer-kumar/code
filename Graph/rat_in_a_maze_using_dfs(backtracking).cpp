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

vector<string> res;
vector<string> findPaths(vector<vector<int>>&a,int n);
void dfs(int row,int col,vector<vector<int>>&a,
	int n,string path,vector<vector<bool>>&visited);



int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> a (n,vector<int>(n,false));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cin>>a[i][j];
    }

    findPaths(a,n);

    for(string x : res)
    	cout<<x<<endl;

	return 0;
}
/*end of main----------------------------->*/

vector<string> findPaths(vector<vector<int>>&a,int n)
{
	vector<vector<bool>> visited (n,vector<bool>(n));
	string path = "";
	/*corner cases*/
	if(a[0][0]==0||a[n-1][n-1]==0) return res;
	dfs(0,0,a,n,path,visited);
	sort(res.begin(),res.end());//sorting formate to output in the question
	return res;
}

void dfs(int row,int col,vector<vector<int>>&a,
	int n,string path,vector<vector<bool>>&visited)
{
	/*border conditions*/
	if(row<0||row>=n||col<0||col>=n) return;

	/*if we encountered 0 or visits the already visited node return asap*/
	if(a[row][col]==0||visited[row][col]==true) return ; 

	/*if we have reached the destination hola!!!*/
	if(row==n-1&&col==n-1)
	{
/*		for(auto x : visited)
		{
			for(bool p: x)
				cout<<p<<" ";
			cout<<endl;
		}
		cout<<"\n\n";*/
		res.push_back(path);
		return ;
	}

	/*marking node visited*/
	visited[row][col] = true;

	/*going up*/
	dfs(row+1,col,a,n,path+'D',visited);

	/*going down*/
	dfs(row-1,col,a,n,path+'U',visited);

	/*goind right*/
	dfs(row,col+1,a,n,path+'R',visited);

	/*going left*/
	dfs(row,col-1,a,n,path+'L',visited);

	/*mark the current node as unvisited*/
	visited[row][col]= false;

}