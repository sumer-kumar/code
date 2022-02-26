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

bool isPrime(int a)
{
	for(int i=2;i*i<a;i++)
	{
		if(a%i==0)
			return false;
	}

	return true;
}

void primeFact(int a,vi &res)
{
	if(a%2==0) res.pb(2);

	while(a%2==0)
	{
		a=a/2;
	}

	for(int i=3;i*i<=a;i+=2)
	{
		if(a%i==0)
		{
			res.pb(i);
		}
		while(a%i==0)
		{
				a=a/i;
		}
	}

	if(a>2)
		res.pb(a);
}

int solve(int x,int y)
{
	vi primes;

	primeFact(y,primes);

	int size = primes.size();

	if(size==0||size==1)
		return size;

	while(size>0)
	{
		if(x%size==0)
			return size;
		size--;
	}

	return 0;
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
    	int x,y;
    	cin>>x>>y;
    	cout<<solve(x,y)<<endl;
    }
	return 0;
}

