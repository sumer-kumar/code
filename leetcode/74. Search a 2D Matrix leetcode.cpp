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


bool bs(vi &a,int k)
{
	int start = 0;
	int end = a.size()-1;

	while(start<=end)
	{
		int mid = (start+end)/2;

		if(a[mid]==k)
			return true;

		if(k<a[mid])
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}

	return false;
}

bool solve(vvi &a,int k)
{
	int r = a.size();
	int c = a[0].size();

	int start = 0;
	int end = r-1;

	while(start<=end)
	{
		int mid = (start+end)/2;

		//if element is in the current row [mid]
		if(k>=a[mid][0] && k<= a[mid][c-1])
		{
			return bs(a[mid],k);
		}

		//if element is present upword of that row
		if(k<a[mid][0])
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}

	return false;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true*/

    vvi a = {
    	{1,4,5,7},
    	{10,11,16,20},
    	{23,30,34,60},
    	{23,30,34,60}
    };

    vvi b = {
    	{1,3}
    };

    int target = 3;

    cout<<solve(b,target)<<endl;

	return 0;
}

