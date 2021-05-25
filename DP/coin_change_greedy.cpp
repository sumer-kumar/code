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
/*NOT ACCURATE =========================================================>*/
int coinChange(vi &a,int M)
{
	pq_d pq(a.begin(),a.end()); /*priority queue max heap*/
	int curr = 0;
	int cnt = 0;
	while(!pq.empty() && curr < M)
	{
		if(curr + pq.top() <= M)
		{
			curr += pq.top();
			cnt++;
		}
		else
		{
			pq.pop();
		}

		if(curr==M)
			break;
	}

	if(curr==M)
		return cnt;
	return -1;
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

    cout<<coinChange(a,M)<<endl;

	return 0;
}

