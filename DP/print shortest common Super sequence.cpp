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
/*using bottom up approach the real dp*/
string solve(string &a,string &b,int aa,int bb)
{
	int dp[aa+1][bb+1];
	cout<<"    ";
	rep(i,0,bb-1)
	cout<<b[i]<<" ";
	cout<<endl;

	rep(i,0,aa)
	{	
		if(i>0)
			cout<<a[i-1]<<" ";
		else
			cout<<"  ";
		rep(j,0,bb)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]= 1 + dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	// return dp[aa][bb];

	int i=aa,j=bb;
	string s = "";
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			s.pb(a[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			s.pb(a[i-1]);
			i--;
		}
		else
		{
			s.pb(b[j-1]);
			j--;
		}
	}
	while(i>0)
	{
		s.pb(a[i-1]);
		i--;
	}
	while(j>0)
	{
		s.pb(b[j-1]);
		j--;
	}

	reverse(s.begin(),s.end());
	cout<<s.size()<<endl;
	return s;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;

    // cout<<recur(a,b,a.size(),b.size())<<endl;
    // cout<<memo(a,b,a.size(),b.size())<<endl;
    cout<<solve(a,b,a.size(),b.size())<<endl;


	return 0;
}

