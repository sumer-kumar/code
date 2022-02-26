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


string solve(vector<string> &a,int n)
{
	string res = "";

	res.pb(a[0][0]);

	int size = a.size();

	rep(i,1,size-1)
	{
		if(a[i-1][1] == a[i][0])
		{
			res.pb(a[i][0]);
		}
		else
		{
			res.pb(a[i-1][1]);
			res.pb(a[i][0]);
		}
	}
	res.pb(a[size-1][1]);

	if(res.size()!=n)
	{
		res.pb('a');
	}

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
    	int n;
    	cin>>n;

    	vector<string> a(n-2);
    	rep(i,0,n-2-1)
    	cin>>a[i];

    	cout<<solve(a,n)<<endl;

    }

	return 0;
}

