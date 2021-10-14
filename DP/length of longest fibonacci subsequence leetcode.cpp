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
	int size = a.size();

	unordered_set<int> us;

	rep(i,0,size-1)
	us.insert(a[i]);

	int mx=0;

	rep(i,0,size-2)
	{
		rep(j,i+1,size-1)
		{
			int prev = a[i];
			int curr = a[j];
			int t = 2;
			while(us.find(prev+curr)!=us.end())
			{
				swap(prev,curr);
				curr = prev+curr;
				t++;
			}
			mx=max(mx,t);
		}
	}
	return mx>=3?mx:0;
}
/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {2,4,7,8,9,10,14,15,18,23,32,50};
    //      1 1 1 3 3 3  3  3  4  5  5  6

    cout<<solve(a)<<endl;

	return 0;
}
