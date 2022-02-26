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


/*
	1 0 2 0 1 2 
	|		  |

*/
void print(vi &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
}

void solve(vi &a)
{	
	//first sorting zeros
	int ind=0;

	int size = a.size();
	rep(i,0,size-1)
	{
		if(a[i]==0)
		{
			swap(a[i],a[ind++]);
		}
	}

	rep(i,0,size-1)
	{
		if(a[i]==1)
		{
			swap(a[i],a[ind++]);
		}
	}

	print(a);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

    vi a = {2,0,2,1,1,0};
    solve(a);

	return 0;
}

