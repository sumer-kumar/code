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


void solve(int low,int high)
{
	queue<int> q;
	vi res;

	rep(i,1,9)
	q.push(i);

	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		if(t>=low && t<=high)
			res.pb(t);

		if(t>high)
			break;

		int num = t%10;
		if(num<9)
		{
			q.push(t*10+(num+1));
		}
	}

	for(int x : res)
		cout<<x<<' ';
	cout<<endl;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int low=100;
    int high=300;

    solve(low,high);

	return 0;
}

