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

void recur(vi &a,int ind,vvi &res)
{
	int size=a.size();
	int sum=-a[ind];	

	int start=ind+1;
	int end=size-1;

	while(start<end)
	{
		int curr_sum = a[start]+a[end];
		if(curr_sum<sum)
		{
			start++;
		}
		else if(curr_sum>sum)
		{
			end--;
		}
		else
		{
			if(res.size()>0 )
			{
				if(res.back()[0]==a[ind] && res.back()[1]==a[start] && res.back()[2]==a[end])
				{

				}
				else
				{
					res.pb({a[ind],a[start],a[end]});
				}
			}
			else
			{
				res.pb({a[ind],a[start],a[end]});
			}

			start++;
			end--;
		}
	}
}

void solve(vi &a)
{
	int size = a.size();

	sort(a.begin(),a.end());

	vvi res;

	rep(i,0,size-1)
	{
		if(i>0 && a[i]==a[i-1])
			continue;
		// cout<<i<<" : "<<a[i]<<endl;
		recur(a,i,res);
	}

	for(auto x : res)
	{
		for(auto p : x)
			cout<<p<<" ";
		cout<<endl;
	}

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    Input: nums = [-1,0,1,2,-1,-4]
	Output: [[-1,-1,2],[-1,0,1]]
	
	[-2,0,0,2,2]
	-4 -1 -1 0 1 2 
	*/

    vi a = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    solve(a);

	return 0;
}

