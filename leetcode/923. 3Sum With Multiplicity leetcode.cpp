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

int dp[3001][301][4];
int recur(vi &a,int curr,int remain,int k)
{
	cout<<curr<<" "<<remain<<" "<<k<<endl;
	if(k==0 && remain==0)
		return 1;

	if(curr==a.size() || remain==0)
		return 0;

	if(dp[curr][k][remain]!=-1)
		return dp[curr][k][remain];

	if(a[curr]>k)
		return 0;

	if(a[curr]<=k)
	{
		return dp[curr][k][remain] = (1ll*recur(a,curr+1,remain-1,k-a[curr])+1ll*recur(a,curr+1,remain,k))%mod;
	}

	return dp[curr][k][remain] = recur(a,curr+1,remain,k);
}

int solve(vi &a,int k)
{
	memset(dp,-1,sizeof(dp));

	sort(a.begin(),a.end());

	return recur(a,0,3,k);
}


int solve2(vi &a,int target)
{
	int size = a.size();
	vi cnt(101,0);
	for(int x : a) 
		cnt[x]++;

	ll res=0;

	rep(i,0,100)
	{
		rep(j,i,100)
		{
			int k = target-i-j;
			if(k<0 || k>target)
				continue;
			if(i==j && j==k)
			{
				res += (cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6);
			}
			else if(i==j && j!=k)
			{
				res += (cnt[i] * (cnt[i]-1)/2)*cnt[k];
			}
			else if(i<j && j<k)
			{
				res += (cnt[i]*cnt[j]*cnt[k]);
			}
		}
	}
	return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: arr = [1,1,2,2,2,2], target = 5
Output: 12*/

    vi a = {0,0,0};
    int target = 0;
    cout<<solve2(a,target)<<endl;

	return 0;
}
