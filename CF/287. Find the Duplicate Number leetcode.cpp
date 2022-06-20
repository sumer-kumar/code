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


int solve(vi &a)
{
	int curr=0;
	int size = a.size();
	int ans=-1;
	while(1)
	{
		if(a[curr]<0 || a[a[curr]]<0)
		{
			ans = a[curr];
			break;
		}
		else
		{
			int t=curr;
			curr = a[curr];
			a[t]=-a[t];
		}
	}

	rep(i,0,size-1)
	a[i]=abs(a[i]);

	return abs(ans);
}


//using linked list cycle method
int solve2(vi &a)
{
	int size = a.size();
	int slow=a[0];
	int fast=a[a[0]];

	while(slow!=fast)
	{
		slow=a[slow];
		fast=a[a[fast]];
	}


	fast=a[0];

	while(slow!=fast)
	{
		slow=a[slow];
		fast=a[fast];
	}

	return slow;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,1};
    cout<<solve(a)<<endl;

	return 0;
}

