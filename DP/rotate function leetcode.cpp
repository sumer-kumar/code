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


int recur(vi &a,int k)
{
	if(k<0)
		return 0;

	int size = a.size();
	int sum = 0;
	rep(i,0,size-1)
	{
		sum += ((i+k)%size)*a[i];
	}

	return max(sum,recur(a,k-1));
}


int solve(vi &a)
{
	return recur(a,a.size()-1);
}

int solve2(vi &A)
{
	vi a(A.begin(),A.end());
	a.insert(a.end(),A.begin(),A.end());

	// for(int x : a)
	// 	cout<<x<<' ';
	// cout<<endl;

	int sum = 0;
	for(int x : A)
		sum += x;

	int size = A.size();
	int prev = 0;
	int res = 0;

	rep(i,0,size-1)
	{
		prev += i*a[i];
	}


	rep(i,1,size-1)
	{
		int curr = prev - (sum-a[i-1]) + a[i-1]*(size-1);
		res = max(res,max(prev,curr));
		prev = curr; 
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {4,3,2,6};

    cout<<solve2(a)<<endl;

	return 0;
}

