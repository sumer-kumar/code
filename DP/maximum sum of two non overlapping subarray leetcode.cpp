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
//we are assuming that max of x len will be from left side
//and max of y len will be from right side
int no_recur(vi &a,int x,int y)
{
	int size = a.size();

	vi l(size,0); // for x len
	vi r(size,0); // for y len

	int sum = 0;

	//for x len from left
	rep(i,0,x-1)
	{
		sum += a[i];
		l[i]=sum;
	}
	rep(i,x,size-1)
	{
		sum = sum + a[i] - a[i-x];
		l[i] = max(l[i-1],sum);
	}

	//for y len from right
	sum = 0;
	for(int i=size-1;i>=size-y;i--)
	{
		sum += a[i];
		r[i] = sum;
	}
	for(int i=size-y-1;i>=0;i--)
	{
		sum = sum + a[i] - a[i+y];
		r[i] = max(r[i+1],sum);
	}

	int res = INT_MIN;

	for(int i=x-1;i<size-y;i++)
	{
		res = max(res,l[i]+r[i+1]);
	}

	return res;
}

int solve( vi &a,int firstLen,int secondLen)
{
	return max(no_recur(a,firstLen,secondLen),no_recur(a,secondLen,firstLen));
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {3,8,1,3,2,1,8,9,0};
    int firstLen = 3;
    int secondLen = 2;

    cout<<solve(a,firstLen,secondLen)<<endl;

	return 0;
}

