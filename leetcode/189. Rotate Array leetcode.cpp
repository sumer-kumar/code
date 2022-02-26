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

// 1 2 3 4 5 6 
// 0 1 2 3 4 5

void print(vi &a)
{
	for(int x : a)
		cout<<x<<' ';
	cout<<endl;
}

void solve(vi &a,int k)
{
	int size=a.size();
	k=k%size;
	reverse(a.begin(),a.end());
	print(a);

	reverse(a.begin(),a.begin()+k);
	print(a);

	reverse(a.begin()+k,a.end());

	print(a);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]*/
    vi a = {1,2,3,4,5,6,7};
    int k=3;
    solve(a,k);

	return 0;
}

