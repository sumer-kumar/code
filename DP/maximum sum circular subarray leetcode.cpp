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

int kadane(vi &a)
{
	int size = a.size();
	int curr_max = a[0];
	int res_max = a[0];

	rep(i,1,size-1)
	{
		curr_max = max(a[i],curr_max+a[i]);
		res_max = max(res_max,curr_max);
	}
	return res_max;
}

int solve(vi &a)
{
	//calculate ans when there is no circular subarray
	int ans_1 = kadane(a);

	//calculate ans when there is circular subarray

	//calculate the sum of all elements
	int sum = 0;
	for(int x : a)
		sum+=x;

	//invert the signs
	for( int &x : a)
		x=-x;
	
	//calculate now max subarray from this array 
	//whose sign inversion will be minimum for original array
	int t = kadane(a);
	int ans_2 = sum+t;
	
	if(ans_2==0)
		return ans_1;

	return max(ans_1,ans_2);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {-1,-2,-3};

    cout<<solve(a)<<endl;

	return 0;
}

