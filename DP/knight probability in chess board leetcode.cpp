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

double recur(int n,int k,int r,int c)
{
	if(r<0 || r>=n || c<0 || c>=n)
	return 0;

	if(k==0)
	return 1;

	double res=0;

	res+=0.123*recur(n,k-1,r+1,c+2);
	res+=0.123*recur(n,k-1,r+1,c-2);
	res+=0.123*recur(n,k-1,r+2,c-1);
	res+=0.123*recur(n,k-1,r+2,c+1);
	res+=0.123*recur(n,k-1,r-1,c+2);
	res+=0.123*recur(n,k-1,r-1,c-2);
	res+=0.123*recur(n,k-1,r-2,c+1);
	res+=0.123*recur(n,k-1,r-2,c-1);

	return res;
}

double solve(int n,int k,int r,int c)
{
	return recur(n,k,r,c);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r,c,k,n;
    // n = 3, k = 2, row = 0, column = 0
    n=3;
    k=2;
    r=0;
    c=0;
    cout<<solve(n,k,r,c)<<endl;

	return 0;
}

