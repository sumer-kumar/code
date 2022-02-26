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

bool cmp(vi &a,vi &b)
{
	if(a[0]==b[0])
	{
		return a[1]>b[1];
	}

	return a[0]<b[0];
}

int solve(vvi &a)
{
	int size = a.size();

	if(size==1 || size==0)
		return size;

	sort(a.begin(),a.end(),cmp);

	for(auto x : a)
	{
		for(int p : x)
		cout<<p<<" ";
		
		cout<<endl;
	}

	int cnt=1;
	int last=0;


	rep(i,1,size-1)
	{
		//overlapping
		if(a[i][0]>=a[last][0] && a[i][1]<=a[last][1])
		{
			continue;
		}
		else
		{
			last = i;
			cnt++;
		}
	}

	return cnt;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2*/

    vvi a = {
    	{1,4},
    	{3,6},
    	{2,8}
    };

    cout<<solve(a)<<endl;

	return 0;
}

