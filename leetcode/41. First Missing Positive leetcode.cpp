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

	for(int i=size-1;i>=0;i--)
	{
		while(a[i]>0 && a[i]<=size && a[a[i]-1]!=a[i])
		{
			swap(a[a[i]-1],a[i]);
		}
	}

	rep(i,0,size-1)
	{
		if(i+1!=a[i])
			return i+1;
	}

	return size+1;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [3,4,-1,1]
Output: 2*/

    vi a = {
2147483647,100000,1,3,2,4,5,6,7,100001};
    cout<<solve(a)<<endl;

	return 0;
}

