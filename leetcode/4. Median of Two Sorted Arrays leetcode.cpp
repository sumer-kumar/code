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

// 0 1 2 3 4 5 6 7

double solve(vi &a,vi &b)
{
	if(a.size()>b.size())
		return solve(b,a);

	int sizea = a.size();
	int sizeb = b.size();

	int start = 0;
	int end = sizea;

	while(start<=end)
	{
		int cut1 = (start+end)/2;
		int cut2 = (sizea+sizeb+1)/2-cut1;

		int l1 = cut1==0?INT_MIN:a[cut1-1];
		int l2 = cut2==0?INT_MIN:b[cut2-1];

		int r1 = cut1==sizea?INT_MAX: a[cut1];
		int r2 = cut2==sizeb?INT_MAX:b[cut2];

		if(l1<=r2 && l2<=r1)
		{
			if((sizea+sizeb)%2==0)
				return (max(l1,l2)+min(r1,r2))/2.0;
			else
				return max(l1,l2);
		}
		else if(l1>r2)
		{
			end = cut1-1;
		}
		else
		{
			start = cut1+1;
		}
	}

	return 0.0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000*/

    vi a = {1,2};
    vi b = {3,4};

    cout<<solve(a,b)<<endl;

	return 0;
}

