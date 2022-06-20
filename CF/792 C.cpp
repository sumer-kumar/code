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





void solve(vvi &a,int r,int c)
{
	vi bad;
	for(int i=0;i<r && bad.size()==0;i++)
	{
		vi b = a[i];
		sort(b.begin(),b.end());

		rep(j,0,c-1)
		{
			if(a[i][j]!=b[j])
				bad.pb(j);
		}
	}

	if(bad.size()>=3)
	{
		cout<<(-1)<<endl;
		return;
	}

	if(bad.size()==0)
	{
		cout<<"1 1"<<endl;
		return;
	}

	//swap two columns
	rep(i,0,r-1)
	{
		swap(a[i][bad[0]],a[i][bad[1]]);
	}

	//check if there is any conflict or not
	rep(i,0,r-1)
	{
		rep(j,1,c-1)
		{
			if(a[i][j]<a[i][j-1])
			{
				cout<<(-1)<<endl;
				return;
			}
		}
	}


	cout<<(bad[0]+1)<<" "<<(bad[1]+1)<<endl;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		int r,c;
		cin>>r>>c;

		vvi a(r,vi(c));

		rep(i,0,r-1)
		ininvi(a[i]);

		solve(a,r,c);
	}   

    

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