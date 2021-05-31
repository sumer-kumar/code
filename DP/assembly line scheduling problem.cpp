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


/*can be converted into bottom up dp*/
int recur(vvi& a,vvi& t,vi& e,vi& x,int i,int j)
{
	/*base conditions*/
	if(j==0)
		return a[i][j]+e[i];

	int u,h,d;

	u=h=d=INT_MAX;
	if(i-1>=0)
	u = recur(a,t,e,x,i-1,j-1)+t[i-1][j];

	h = recur(a,t,e,x,i,j-1);
	
	if(i+1<2)
	d = recur(a,t,e,x,i+1,j-1)+t[i+1][j];

	return min(h,min(u,d))+a[i][j];
}

int recurFun(vvi& a,vvi& t,vi& e,vi& x,int n)
{
	int top = recur(a,t,e,x,0,n-1)+x[0];
	int down = recur(a,t,e,x,1,n-1)+x[1];

	return min(top,down);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vvi a(2,vi(n));
    vvi t(2,vi(n));

    rep(i,0,1)
    {
    	rep(j,0,n-1)
    	cin>>a[i][j];
    }
    rep(i,0,1)
    {
    	rep(j,0,n-1)
    	cin>>t[i][j];
    }



    vi e(2);
    cin>>e[0]>>e[1];

    vi x(2);
    cin>>x[0]>>x[1];

    cout<<recurFun(a,t,e,x,n)<<endl;

	return 0;
}

