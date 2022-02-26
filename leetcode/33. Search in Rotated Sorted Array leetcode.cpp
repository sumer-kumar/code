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

//start end is inclusive
int bs(vi &a,int start,int end,int k)
{

	while(start<=end)
	{
		int mid = (end+start)/2;

		// cout<<mid<<endl;

		if(k==a[mid])
			return mid;

		if(a[mid]<k)
			start=mid+1;
		else
			end=end-1;
	}

	return -1;
}

int solve(vi &a,int k)
{

	int size = a.size();

	int start=0;
	int end=size-1;

	// if already sorted
	if(a[start]<a[end])
	{
		return bs(a,start,end,k);
	}

	int mx=INT_MIN;
	int pvt;
	while(start<=end)
	{
		int mid = (start+end)/2;

		// cout<<start<<' '<<end<<" "<<mid<<endl;

		//check first part
		if(a[start]<=a[mid])
		{
			start = mid+1;
			if(a[mid]>mx)
			{
				pvt=mid;
				mx=a[mid];
			}
		}
		else
		{
			end = mid-1;
			if(a[mid]>mx)
			{
				pvt=mid;
				mx=a[mid];
			}
		}
	}

	// cout<<pvt<<endl;

	if(k>=a[0])
		return bs(a,0,pvt,k);

	if(k<=a[size-1])
		return bs(a,pvt+1,size-1,k);

	return -1;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
[8,9,2,3,4]
 0 1 2 3 4
9

*/

    vi a = {8,9,2,3,4};
    int k=9;

    cout<<solve(a,k)<<endl;

	return 0;
}

