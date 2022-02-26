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


int recur(vi &a)
{
	int size = a.size();
	int cnt1=0;
	int cnt0=0;
	rep(i,0,size-1)
	{
		if(a[i]==1)
			cnt1++;
		else
			cnt0++;
	}

	int mn = size;
	int cnt = 0;

	for(int i=0;i<cnt1;i++)
	{
		cnt += a[i]==1?1:0;
	}

	mn = cnt1-cnt;
	for(int i=cnt1;i<size;i++)
	{
		if(a[i-cnt1]==1)
			cnt--;
		if(a[i]==1)
			cnt++;
		mn = min(mn,cnt1-cnt);
	}

	cnt=0;
	for(int i=0;i<cnt0;i++)
	{
		cnt += a[i]==0?1:0;
	}

	mn = min(mn,cnt0-cnt);
	for(int i=cnt0;i<size;i++)
	{
		if(a[i-cnt0]==0)
			cnt--;
		if(a[i]==0)
			cnt++;
		mn = min(mn,cnt0-cnt);
	}

	return mn;
}

int solve(vi &a)
{
	int size = a.size();
	return recur(a);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {0,1,1,1,0,0,1,1,0};

    cout<<solve(a)<<endl;

	return 0;
}

