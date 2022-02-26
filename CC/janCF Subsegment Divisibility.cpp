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

ll sum1(vi &a,int i,int j)
{
	ll sum=0;
	for(;i<=j;i++)
		sum+=a[i];
	return sum;
}

void solve(int n)
{
	ll sum=1;
	vi a;
	a.pb(1);
	cout<<1<<" ";
	ll cnt=2;
	rep(i,2,n)
	{
		while((sum+cnt)%i==0)
		{
			cnt+=2;
		}
		sum += cnt;
		a.pb(cnt);
		cnt++;
	}

	int size = a.size();
	for(int i=0;i<size-2;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sum1(a,i,j)%(j-i+1)==0)
			{
				if((i+1)%2==0)
			}
		}
	}

	cout<<endl;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;
    	solve(n);
    }

	return 0;
}

