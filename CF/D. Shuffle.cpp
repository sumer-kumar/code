#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
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

int dp[5001][5001];
int recur(int one,int zero)
{
	if(one==0 || zero==0)
		return 1;
	if(dp[one][zero]!=-1)
		return dp[one][zero];
	return dp[one][zero]=(1ll*recur(one-1,zero)+1ll*recur(one,zero-1))%mod;
}

int solve2(vector<char> a,int k)
{
	int size = a.size();
	for(int i=size-1;i>=0;i--)
	{
		if(a[i]=='1')
		{
			a.pop_back();
			break;
		}
		a.pop_back();
	}

	size = a.size();

	if(k==0)
	{
		int cnt=0;
		for(int i=0;i<size;i++)
		{
			if(a[i]=='1')
			{
				for(int j=i+1;j<size;j++)
					if(a[j]=='1')
						cnt++;
					break;
			}
		}
		return cnt+1;
	}
	int start=0;
	int cnt=0;
	int res=0;

	for(int i=0;i<size;i++)
	{
		if(a[i]=='1')
			cnt++;
		if(cnt>k)
		{
			if(k>0 && (i-start-k)>0)
			res = (1ll*res+1ll*recur(k,i-start-k))%mod;
			while(start<size && start<=i)
			{
				if(cnt==1)
					break;
				if(a[start]=='1')
					cnt--;
				start++;
			}
		}
	}
	if(cnt==k && (size-start-k)>0){
		res = (1ll*res + 1ll*recur(k,size-start-k))%mod;
	}

	return res;
}

int solve3(vector<char> &a,int k=1)
{
	if(k==0)
		return 1;
	int size = a.size();
	int start=0;
	int cnt=0;
	int res=1;

	// cout<<recur(2,2)<<" "<<recur(2,3)<<endl;

	for(int i=0;i<size;i++)
	{
		if(a[i]=='1')
			cnt++;
		if(cnt>k)
		{
			res = (1ll*res+1ll*recur(k,i-start-k)-1+1ll*mod)%mod;
			while(start<size && start<=i)
			{
				if(cnt==1)
					break;
				if(a[start]=='1')
					cnt--;
				start++;
			}
		}
	}
	if(cnt==k && (size-start-k)>0){
		res = (1ll*res+1ll*recur(k,size-start-k)-1+1ll*mod)%mod;
	}

	return res;
}

int solve(vector<char> &a,int k)
{
	memset(dp,-1,sizeof(dp));
	if(k==0)
		return 1;
	if(k==1)
		return solve3(a);
	int size = a.size();
	int start=0;
	int cnt=0;
	int res=0;

	for(int i=0;i<size;i++)
	{
		if(a[i]=='1')
			cnt++;
		if(cnt>k)
		{
			if(k>0 && (i-start-k)>0)
				res = (1ll*res+1ll*recur(k,i-start-k))%mod;
			while(start<size && start<=i)
			{
				if(cnt==k)
					break;
				if(a[start]=='1')
					cnt--;
				start++;
			}
		}
	}
	if(cnt==k && (size-start-k)>0){
		res = (1ll*res+1ll*recur(k,size-start-k))%mod;
	}

	int cnti = solve2(a,k-1);
	// cout<<cnti<<endl;

	if(res==0 && cnt<k)
		return 1;

	return (1ll*res-1ll*cnti+mod)%mod;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    vector<char> a(n);
    rep(i,0,n-1) cin>>a[i];

    cout<<solve(a,k)<<endl;

	return 0;
}

