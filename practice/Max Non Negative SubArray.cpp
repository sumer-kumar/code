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

void solve(vi &a)
{
	int start=-1;
	int end=-1;

	int curr_start=0;
	int curr_end=0;

	ll sum = 0;
	ll max_sum = 0;

	int size = a.size();

	for(int i=0;i<size;i++)
	{

		curr_start=i;
		curr_end=i;
		sum = 0;
		while(i<size && a[i]>=0)
		{
			sum += a[i];
			i++;
			curr_end++;
		}

		if(sum>max_sum)
		{
			start = curr_start;
			end = curr_end-1;
		}
		else if(sum == max_sum)
		{
			if(end-start < curr_end-curr_start)
			{
				start = curr_start;
				end = curr_end-1;			
			}
		}

		cout<<start<<" "<<end<<endl;
	}

	cout<<start<<" "<<end<<endl;
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
    solve(a);
    cout<<"gdrg"<<endl;

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