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


ll fun(vll &a)
{
	int size = a.size();
	vll left(size,0);
	left[0] = a[0];
	ll cnt = 0;
	if(a[0]!=0)
	{
		rep(i,1,size)
		{
			if(i==size || a[i]==0)
			{
				ll mn = 0;
				cout<<i<<endl;
				for(ll x : left)
					cout<<x<<" ";
				cout<<endl;

				for(int j=i-1;j>=0;j--)
				{
					if(mn==left[j])
					{
						a[j] -= mn;
					}
					else
					{
						cnt += (left[j]-mn);
						mn = left[j];
						a[j] -= mn;
						cout<<j<<" "<<mn<<" "<<a[j]<<endl;
					}
				}
				break;
			}
			left[i] = min(left[i-1],a[i]);
		}
	}

	for(ll x : a)
		cout<<x<<" ";
	cout<<endl;

	cout<<"cnt--"<<cnt<<endl;

	return cnt;
}

ll solve(vll &a,int size)
{
	int mn = *min_element(a.begin(),a.end());
	
	ll cnt = 0;
	if(mn<0){
	for(ll &x : a)
		x += -mn;
	cnt += -mn;
	}
	for(ll x : a)
		cout<<x<<" ";
	cout<<endl;

	cnt += fun(a);
	reverse(a.begin(),a.end());
	cout<<"esf"<<endl;
	cnt += fun(a);
	
	rep(i,1,size-2)
	{
		cnt += 3*a[i];
	}

	return cnt;
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
		int n;
		cin>>n;
		vll a(n);
		inllvi(a);
		cout<<solve(a,n)<<endl;
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