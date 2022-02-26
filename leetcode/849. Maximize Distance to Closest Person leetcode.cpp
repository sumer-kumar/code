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
	int start = -100001;
	int end = 0;

	int mx = 0;

	int size = a.size();

	for(int i=0;i<size;i++)
	{
		//empty seat
		if(a[i]==0)
		{
			while(end<=i || (end<size && a[end]==0))
			{
				end++;
			}
			if(end==size)
			{
				end = INT_MAX;
			}
			mx = max(mx,min(i-start,end-i));
			// cout<<start<<" "<<i<<" "<<end<<" "<<mx<<endl;
		}
		else
		{
			start = i;
		}
	}
	return mx;
}
//  1 0 0 0 1 0 0
//  0 1 2 3 4 5 6

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,0,0,1,0,0,0};
    cout<<solve(a)<<endl;

	return 0;
}

