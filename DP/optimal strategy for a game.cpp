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

/*recursive approach */
/*when enemy player don't play optimally*/
int recur(vi &a,int i,int j)
{
	if(i>j)
		return 0;
	if(j-i+1==2)
		return max(a[i],a[j]);

	/*when i choose the first element*/
	/*and enemy choose the first of remaining*/
	int m1 = a[i]+recur(a,i+2,j);

	/*enemy choose the last of remaining*/
	int m2 = a[i]+recur(a,i+1,j-1);


	/*when i choose the last element*/
	/*and enemy choose the first of remaining*/
	int m3 = a[j]+recur(a,i+1,j-1);

	/*enemy choose the last element*/
	int m4 = a[j]+recur(a,i,j-2);

	return max(max(m1,m2),max(m3,m4));
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

    cout<<recur(a,0,n-1)<<endl;

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