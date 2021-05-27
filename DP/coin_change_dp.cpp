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

/*count function*/
int countways(vi &coin,int n,int price)
{
    int dp[n+1][price+1];
    rep(i,0,n)
    {
        rep(j,0,price)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else if(coin[i-1]<=j)
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][price];
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);

    rep(i,0,n-1)
    cin>>a[i];

    int M;
    cin>>M;

    // cout<<"bang"<<endl;
    cout<<countways(a,n,M)<<endl;

	return 0;
}

