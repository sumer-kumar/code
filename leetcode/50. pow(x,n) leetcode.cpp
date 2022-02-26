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

double recur(double a,int p)
{
	double res = 1;
	while(p>0)
	{
		if(p&1)
		{
			res *= a;
		}
		p>>=1;
		a*=a;
	}

	return res;
}

double solve(double a,int p)
{
	if(p==INT_MIN)
		return 0;
	double x = recur(a,abs(p));
	return p<0?(double)(1/x):x;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cout<<solve(2,5)<<endl;

	return 0;
}

