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


bool check(vi &a,int h,int mid)
{
	int cnt=0;
	
	int size=a.size();

	rep(i,0,size-1)
	{
		if(a[i]%mid==0)
		{
			cnt += a[i]/mid;
		}
		else
		{
			cnt += (a[i])/mid+1;
		}
	}
	return cnt>h?false:true;
}

int solve(vi &a,int t)
{
	int size=a.size();

	int start = 1;
	int end = a[0];

	rep(i,1,size-1)
	{
		end=max(end,a[i]);
	}

	int ans=end;

	// cout<<check(a,t,22)<<endl;

	while(start<end)
	{
		int mid = (end+start)/2;
		// cout<<start<<" "<<end<<" "<<mid<<" "<<ans<<endl;

		if(check(a,t,mid))
		{
			ans=mid;
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}

	return ans;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: piles = [3,6,7,11], h = 8
	Output: 4*/

    /*[30,11,23,4,20]
	  6
	  23
	*/

    vi a = {30,11,23,4,20};
    int h=6;

    cout<<solve(a,h)<<endl;

	return 0;
}

