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


string solve(string &a,int size)
{
	if(size<2)
		return "YES";
	if(size==2)
		return a[0]==a[1]?"NO":"YES";

	rep(i,0,size-1)
	{
		if(i+2<=size)
		{
			if(a[i]==a[i+1])
				return "NO";
		}
		if(i+3<=size)
		{
			if(a[i]==a[i+2])
				return "NO";
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

    	string a;
    	cin>>a;

    	cout<<solve(a,n)<<endl;
    }


	return 0;
}

