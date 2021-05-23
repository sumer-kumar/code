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

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
/*recursive approach o(3^n)*/
ll recur(ll n)
{
	if(n==1 || n== 2)
		return n;
	if(n==3)
		return 4;

	return (recur(n-1)%mod + recur(n-2)%mod + recur(n-3)%mod)%mod;
}

/*optimal*/
ll solve(ll n)
{
	if(n==1 || n==2)
		return n;
	if(n==3)
		return 4;
	vll a(n+1,0);
	/*initial conditions*/
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=4;

	for(int i=4;i<=n;i++)
	{
		a[i] = (a[i-1]%mod+a[i-2]%mod+a[i-3])%mod; 
	}

	return a[n];
}

/*more optimal*/
int printCountDP(int dist)
{
        //Create the array of size 3.
        int  ways[3] , n = dist;
         
        //Initialize the bases cases
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
         
        //Run a loop from 3 to n
        //Bottom up approach to fill the array
        for(int i=3 ;i<=n ;i++)
            ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3];
         
        return ways[n%3];
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    // cout<<recur(n)<<endl;
    cout<<solve(n)<<endl;
	return 0;
}