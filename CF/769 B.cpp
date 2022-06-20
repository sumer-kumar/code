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

int bitLen(int n)
{
	int t=n;
	int cnt=0;
	while(t>0)
	{
		t>>=1;
		cnt++;
	}
	return cnt;
}

void solve(int n)
{

	if(n==1)
	{
		cout<<0<<endl;
		return;
	}

	int len = bitLen(n-1);

	int mx = pow(2,len-1);

	// cout<<mx<<endl;

	for(int i=mx-1;i>=0;i--)
		cout<<i<<" ";

	for(int i=mx;i<n;i++)
		cout<<i<<" ";
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

    	solve(n);
    }

	return 0;
}

