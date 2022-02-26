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

bool check(vi &a,int i,unordered_map<int,int> &um)
{
	int cnt = 0;
	int size = a.size();
	for(int j=0;j<i;j++)
	{
		if(um[j]!=0)
			um[j]--;
		else
		{
			int t = j-1;
			// cout<<j<<"--"<<endl;
			while(t>=0)
			{
				// cout<<t<<" "<<um[t]<<" "<<endl;
				if(um[t]>0)
				{
					cnt += (j-t);
					um[t]--;
					break;
				}
				t--;
			}
			// cout<<endl;
			if(t<0){
				for(int k=i;k<=size;k++)
				{
					cout<<"-1 ";
				}
				return false;
			}
		}
	}

	cnt += um[i];

	cout<<cnt<<" ";

	return true;
}

void solve(vi &a)
{
	int size = a.size();
	unordered_map<int,int> um;

	rep(i,0,size-1)
	um[a[i]]++;

	//check for zero
	cout<<um[0]<<" ";

	rep(i,1,size)
	{
		unordered_map<int,int> u;
		for(int j=0;j<=i;j++)
			u[j] = um[j];

		if(check(a,i,u)==false)
			break;
	}

	cout<<endl;

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

    	solve(a);
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