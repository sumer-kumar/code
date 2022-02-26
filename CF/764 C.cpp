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

void add_effect(vi &cnt,int a)
{
	int size = cnt.size()-1;

	while(a>0)
	{
		if(a<=size)
		{
			cnt[a]++;
		}
		a /= 2;
	}
}

void remove_effect(vi &cnt,int a)
{
	int size = cnt.size()-1;
	while(a>0)
	{
		cnt[a]--;
		a /= 2;
	}
}

string solve(vi &a)
{
	int size = a.size();
	vi cnt(size+1,0);

	rep(i,0,size-1)
	{
		add_effect(cnt,a[i]);
	}

	for(int i=size;i>0;i--)
	{
		if(cnt[i]<=0)
			return "No";
		remove_effect(cnt,i);
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
/*unordered_map<int,unordered_map<int,bool>> um;
bool isPossible(int a,int k)
{
	int t = a;
	while(t>k)
	{
		t = t/2;
		um[a][t]=true;
	}

	return t==k?true:false;
}

bool recur(vi &a,vi &vis,int curr)
{
	int size = a.size();

	if(curr>size)
		return true;

	rep(i,0,size-1)
	{
		if(vis[i]==0 && (curr == a[i]|| um[a[i]][curr]==true||isPossible(a[i],curr)))
		{
			vis[i]=1;
			if(recur(a,vis,curr+1)==true)
				return true;
			vis[i]=0;
		}
	}

	return false;
}

string solve(vi &a)
{
	um.clear();
	int size = a.size();
	vi vis(size,0); //array ke index ka

	return recur(a,vis,1)==true?"Yes":"No";
}

*/