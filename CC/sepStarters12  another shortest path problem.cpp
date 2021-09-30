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


long solve(long n,long m,long x,long y)
{

	if(n>m)
		swap(n,m);

	if(n==1)
	{
		// if(m==1)
		// 	return 0;

		return (m-1)*x;
	}


	if(2*x<=y)
	{
		return ((n-1)+(m-1))*x;
	}

	long res = (n-1)*y;
	res += (m-n)*x;

	return res;
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
    	long n,m,x,y;
    	cin>>n>>m>>x>>y;

    	cout<<solve(n,m,x,y)<<endl;
    }

	return 0;
}

