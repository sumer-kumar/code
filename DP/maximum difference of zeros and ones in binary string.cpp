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

int maxSumSub(vi &a,int n)
{
	int max_end_here = a[0];
	int max_till_now = a[0];

	rep(i,1,n-1)
	{
		max_end_here = max(max_end_here+a[i],a[i]);
		max_till_now = max(max_till_now,max_end_here);
	}
	return max_till_now;
}

int findAns(string s)
{
	int n = s.size();
	vi a(n,1);
	vi b(n,-1);
	rep(i,0,n-1)
	{
		if(s[i]=='1')
			a[i]=-1;
	}
	return maxSumSub(a,n);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<"\n";
    cout<<findAns(s)<<endl;

	return 0;
}

