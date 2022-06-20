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

int lessEqual(vector<vector<int>> &a,int k)
{

	int r = a.size();
	int c = a[0].size();

	int i=r-1;
	int j=0;

	int cnt=0;

	while(i>=0 && j<c)
	{
		if(a[i][j]>k)
			i--;
		else
		{
			cnt += (i+1);
			j++;
		}
	}
	return cnt;
}

int solve(vector<vector<int>> &a,int k)
{
	int r = a.size();
	int c = a[0].size();

	int start = a[0][0]; //first element (smallest)
	int end = a[r-1][c-1]; // last element (largest)

	while(start<end)
	{
		int mid = start+(end-start)/2;

		int rank = lessEqual(a,mid);
		if(rank<k)
		{
			start = 1+mid;
		}
		else
		{
			end = mid;
		}
	}

	return start;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13*/

    vvi a = {
    	{1,5,9},
    	{10,11,13},
    	{12,13,15}
    };

    int k = 8;

    cout<<solve(a,k)<<endl;

	return 0;
}

/*

We will be trying this question using binary search 

a[0][0] will be the smallest element
and a[r-1][c-1] will be the largest element (r=row size and c=column size)

start = a[0][0];
end = a[r-1][c-1];

mid = (start+end)/2;
more efficiently
mid = start + (end-start)/2;

then we will calculate the number of elements which is less than or equal to the mid element
for which you can refer the problem "240. Search a 2D Matrix II" 
I will be doing a little modification to the solution

and after calculating the number of element which is less than or equal to the mid (lets call it as "rank")
we will check 
	if (rank<k)
	{
		start = mid+1;
	}
	else
	{
		end = mid;
	}

you will get more clearity when you will go through the code

*/

