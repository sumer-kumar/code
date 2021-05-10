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

void flood_fill(vector<vector<int>>&img,int row,int col, int newcol);
void flood_fill_until(vector<vector<int>>&img,int row,int col, int prev,int newcol);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int row,col;
	// cin>>row>>col;

	// vector<vector<int,int>> a (row,vector<int>(col));

	vector<vector<int>> a = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1}};

	// for(int i=0;i<row;i++)
	// {
	// 	for(int j=0;j<col;j++)
	// 	{
	// 		cin>>a[i][j];
	// 	}
	// }	

	flood_fill(a,4,4,3);	

	return 0;
}

void flood_fill(vector<vector<int>>&img,int row,int col, int newcol)
{
	flood_fill_until(img,row,col,img[row][col],newcol);
	for(auto x : img)
	{
		for(auto y : x)
			cout<<y<<" ";
		cout<<endl;
	}

}

void flood_fill_until(vector<vector<int>>&img,int row,int col, int prev,int newcol)
{
	int rowsize = img.size();
	int colsize = img[0].size();

	if(row < 0 || row >= rowsize || col < 0 || col >=colsize)
		return ;

	/* check if previous */
	if(img[row][col]!=newcol&&img[row][col]==prev)
	{
		img[row][col] = newcol;

		/*send different directions*/
		flood_fill_until(img,row+1,col,prev,newcol);
		flood_fill_until(img,row-1,col,prev,newcol);
		flood_fill_until(img,row,col+1,prev,newcol);
		flood_fill_until(img,row,col-1,prev,newcol);
	}

}