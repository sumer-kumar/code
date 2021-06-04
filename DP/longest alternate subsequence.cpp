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
void ininarr(int a[],int size);
void ininvi(vi &a,int size=0);
void inllarr(ll a[],ll n);
void inllvi(vll &a,ll size=0);




void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
/*O(n^2)*/
int solve1(vi &a,int n)
{
	vvi dp(n+1,vi(2,1));

	int ans =1 ;
	rep(i,1,n-1)
	{
		rep(j,0,i-1)
		{
			if(a[i]<a[j])
			{
				dp[i][0] = max(dp[i][0],dp[j][1]+1);
			}
			else
			{
				dp[i][1] = max(dp[i][1],dp[j][0]+1);
			}

			ans = max(dp[i][1],dp[i][0]);
		}
	}


	return ans;
}

/*O(n)*/
int solve(vi &a,int n)
{
	int m1,m2;
	m1=m2=1;

	rep(i,1,n-1)
	{
		if(a[i]<a[i-1])
		{
			m1=1+m2;
		}
		else
		{
			m2=1+m1;
		}
	}
	return max(m2,m1);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vi a(n);
    ininvi(a);
    cout<<solve(a,n)<<endl;

	return 0;
}







/******INPUT THINGS*********/
void ininarr(int a[],int size)
{
	rep(i,0,size-1)
	{
		cin>>a[i];
	}
}

void ininvi(vi &a,int size)
{
	if(!size)
		size = a.size();
	rep(i,0,size-1)
	cin>>a[i];
}

void inllarr(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cin>>a[i];
}

void inllvi(vll &a,int size)
{
	if(!size)
		size=a.size();
	for(ll i=0;i<size;i++)
		cin>>a[i];
}