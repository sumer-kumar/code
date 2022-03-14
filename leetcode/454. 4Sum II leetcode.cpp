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


int solve(vi &a,vi &b,vi &c,vi &d)
{
	unordered_map<int,int> umab;
	for(int x1 : a)
	{
		for(int x2 : b)
			umab[x1+x2]++;
	}

	int cnt = 0;
	for(int x1 : c)
	{
		for(int x2 : d)
		{
			cnt += umab[-(x1+x2)];
		}
	}

	return cnt;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2*/

    vi a = {1,2};
    vi b = {-2,-1};
    vi c = {-1,2};
    vi d = {0,2};

    cout<<solve(a,b,c,d)<<endl;

	return 0;
}

