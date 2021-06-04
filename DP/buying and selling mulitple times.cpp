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

/*selling multiple times */
/*using peak and valley approach*/
int solve2(vi &a,int n)
{
	int ans = 0;

	rep(i,1,n-1)
	{
		if(a[i]>a[i-1])
			ans+=(a[i]-a[i-1]);
	}
	return ans;
}

/*first find the fault in decreasing pattern */
/*and after that find the falt in increasing pattern
  suppose 5 4 3 6 7 8 2
  here 6 is fault in decreasing pattern and 2 
  is fault in increasing pattern 
*/
int solve(vi &a,int n)
{
	int i=0;
	int ans=0;
	while(i<n)
	{
		while(i<n-1 && a[i]>=a[i+1])
			i++;
		if(i==n-1)
			break;

		int m1 = i++;

		while(i<n && a[i-1]<=a[i])
			i++;

		int m2 = i-1;

		cout<<m1<<" --> "<<m2<<endl;
		ans = a[m2]-a[m1];
	}

	return ans;
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

void inllvi(vll &a,ll size)
{
	if(!size)
		size=a.size();
	for(ll i=0;i<size;i++)
		cin>>a[i];
}