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

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}


void rotate1(int start,int end)
{
	cout<<end<<" ";

	rep(i,start,end-1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}


void solve(int n,int k)
{
	if(n-k==1)
	{
		cout<<(-1)<<endl;
		return ;
	}

	if(n==k)
	{
		rep(i,1,n)
		cout<<i<<" ";
		cout<<endl;
		return ;
	}

	rep(i,1,k)
	{
		cout<<i<<" ";
	}

	rotate1(k+1,n);

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
    	int n,k;
    	cin>>n>>k;

    	solve(n,k);	
    }

	return 0;
}

