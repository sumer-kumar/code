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
	int i=1;
	int res = 0;
	while(i<size-1)
	{
		if(a[i]>a[i-1])
		{
			//increasing len
			int il = 1;
			while(i<size and a[i]>a[i-1])
			{	
				i++;
				il++;
			}

			//when we reach at the end at increasing phase
			if(i==size)
				return res;

			//if two elements are equal in increaing phase
			if(a[i]==a[i-1])
			{
				i++;
				continue;
			}
			
			//decreasing len
			int dl = 1;
			while(i<size-1 and a[i]>a[i+1])
			{
				dl++;
				i++;
			}
			res = max(res,il+dl);
		}
		i++;
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {0,2,2};
    for(int x : a)
    	cout<<x<<" ";
    cout<<endl;

    cout<<solve(a)<<endl;

	return 0;
}

