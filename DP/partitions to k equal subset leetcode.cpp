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


bool recur(vi &a,vector<bool> &vis,int sum,int curr,int k,int tt)
{

	if(curr>=a.size())
	{
		if(sum==0)
		{
			cout<<k<<endl;
			for(bool x : vis)
				cout<<x<<" ";
			cout<<"\n\n";

			if(k==0)
				return true;
			return recur(a,vis,tt,0,k-1,tt);
		}
		return false;
	}

	if(vis[curr]==false && sum-a[curr]>=0)
	{
		vis[curr]=true;
		bool m1 = recur(a,vis,sum-a[curr],curr+1,k,tt);
		vis[curr]=false;

		return m1 || recur(a,vis,sum,curr+1,k,tt);
	}

	return recur(a,vis,sum,curr+1,k,tt);

}


int solve(vi &a,int k)
{
	int size = a.size();
	vector<bool> vis(size,false);

	int sum = 0;
	rep(i,0,size-1)
	sum+=a[i];

	if(sum%k!=0)
		return false;

	return recur(a,vis,sum/k,0,k-1,sum/k);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //sum = 5
	vi a = {4,3,2,3,5,2,1};
	int k=4;
	cout<<solve(a,k)<<endl;    

	return 0;
}

