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
/*
	idea is to design two binary search
	one moves to left when even when found the element
	one moves to right
*/
// start and end is inclusive


// moves to right
int bs1(vi &a,int start,int end,int k)
{
	int res=-1;

	while(start<=end)
	{
		int mid = (start+end)/2;

		if(a[mid]==k)
		{
			res = mid;
			start=mid+1;
		}
		else if(a[mid]<k)
		{
			start = mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	return res;
}

//moves to left
int bs2(vi &a,int start,int end,int k)
{
	int res=-1;

	while(start<=end)
	{
		int mid = (start+end)/2;

		if(a[mid]==k)
		{
			res = mid;
			end=mid-1;
		}
		else if(a[mid]<k)
		{
			start = mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	return res;
}


vi solve(vi &a,int k)
{
	int size = a.size();
	int x = bs2(a,0,size-1,k);
	if(x==-1)
		return {-1,-1};
	int y = bs1(a,x,size-1,k);

	return {x,y};
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

    vi a = {5,7,7,8,8,10};
    int k=6;

    vi res = solve(a,k);

    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;

	return 0;
}

