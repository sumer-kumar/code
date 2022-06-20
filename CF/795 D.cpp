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
string solve(vi &a)
{
	int size = a.size();

	ll max_so_far = a[0];
	ll max_ending_here = a[0];
	
	vi res;

	for (int i = 1; i < size; i++) 
	{
	    max_ending_here = max(max_ending_here + 1ll*a[i], 1ll*a[i]);
	    // max_so_far = max(max_ending_here, max_so_far);

	    if(max_so_far<max_ending_here)
	    {
	    	max_so_far=max_ending_here;
	    	res = {i};
	    }
	    else if(max_so_far == max_ending_here)
	    {
	    	res.pb(i);
	    }
	}

	rep(i,0,res.size()-1)
	{
		ll sm = 0;
		ll mx = INT_MIN;
		for(int j=res[i];j>=0;j--)
		{
			sm = sm + 1ll*a[j];
			mx = max(mx,1ll*a[j]);
			if(sm==max_so_far)
			{
				if(mx<max_so_far)
					return "NO";
				break;
			}
		}
	}


	return "YES";
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

    	vi a(n);
    	ininvi(a);

    	cout<<solve(a)<<endl;
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