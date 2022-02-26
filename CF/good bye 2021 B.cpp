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


string solve(vector<char> &a)
{
	int size = a.size();

	int k = 1;
	if(a[0]!=a[1])
	rep(i,1,size-1)
	{
		if(a[i]>a[i-1])
			break;
		k++;
	}
	else
	{
		rep(i,1,size-1)
		{
			if(a[i]>=a[i-1])
				break;
			k++;
		}	
	}

	string res = "";
	rep(i,0,k-1)
	res.pb(a[i]);

	string st = res;
	reverse(st.begin(),st.end());

	return res+st;
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
    	vector<char> a(n);

    	rep(i,0,n-1)
    	cin>>a[i];

    	cout<<solve(a)<<endl;
    }

	return 0;
}

