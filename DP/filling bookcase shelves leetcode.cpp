#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef priority_queue<int> pq_d;
typedef priority_queue<int,vector<int>,greater<int>> pq_a;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
int dp[1000][1000];
int recur(vvi &a,int curr,int max_h,int shelf_width,int shelf_width_full)
{
	/*base condition*/
	if(curr>=a.size())
		return max_h;

	if(dp[curr][shelf_width]!=-1)
		return dp[curr][shelf_width];

	/*if we can put the book in the same shelf*/
	if(shelf_width-a[curr][0]>=0)
	{	
		/*including the book in the same shelf */
		int m1 = recur(a,curr+1,max(max_h,a[curr][1]),shelf_width-a[curr][0],shelf_width_full);

		/*excluding the book from current shelf and putting it to next shelf*/
		/*so we have to add the heigth of previous shell*/
		int m2 = max_h + recur(a,curr+1,a[curr][1],shelf_width_full-a[curr][0],shelf_width_full);

		return dp[curr][shelf_width] = min(m1,m2);
	}

	/*we don't have any other option except to put the book in other shelf*/
	return dp[curr][shelf_width] = max_h + recur(a,curr+1,a[curr][1],shelf_width_full-a[curr][0],shelf_width_full);
}

int solve(vvi &books,int shelf_width)
{
	memset(dp,-1,sizeof(dp));
	return recur(books,0,0,shelf_width,shelf_width);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4*/
    /*books = [[1,3],[2,4],[3,2]], shelfWidth = 6*/
    vvi books = {
    	/*{width,height}*/
    	{1,1},
    	{2,3},
    	{2,3},
    	{1,1},
    	{1,1},
    	{1,1},
    	{1,2}
    	// {1,3},
    	// {2,4},
    	// {3,2}
    };

    int shelf_width = 4;

    cout<<solve(books,shelf_width)<<endl;

	return 0;
}

