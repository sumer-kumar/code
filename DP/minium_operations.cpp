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

/*simple greedy====not correct*/
int grdy(int n)
{
	if(n==1||n==0)
		return n;
	int curr=0;
	int cnt =0;

	while(curr<n)
	{
		if(curr*2<=n && curr*2 >= curr+1)
			curr *= 2;
		else
			curr++;
		cnt++;
	}
	return cnt;
}

/*recursive approach brute force===wrong*/
int recur(int n,int cnt = 0)
{	
	if(n==0||n==1||n==2)
		return cnt+n;

	return min(recur((n+1)/2,cnt+1),recur(n-1,cnt+1));
}

/*successfull O(n^2)*/
int recur2(int n,int i=0,int cnt = 0)
{
	if(i>n)
		return INT_MAX;

	if(i==0 && cnt> 0)
		return INT_MAX;

	if(i==n)
		return cnt;

	int m1 = recur2(n,i*2,cnt+1);
	int m2 = recur2(n,i+1,cnt+1);

	return min(m1,m2);
}

/*memoization not working*/
vi lookup(1001,-1);
int memo(int n,int i=0,int cnt = 0 )
{
	if(i>n)
		return INT_MAX;
	if(i==0 && cnt>0)
		return INT_MAX;

	if(i==n)
		return cnt;

	int m1 = INT_MAX;
	if(i*2<=n)
	{
		if(lookup[i*2]==-1)
			lookup[i*2]=memo(n,i*2,cnt+1);
		int m1 = lookup[i*2];
	}

	if(lookup[i+1]==-1)
		lookup[i+1]=memo(n,i+1,cnt+1);

	return min(m1,lookup[i+1]);
}
/*gfg solution*/
int minOperation(int n)
{
    int count = 0;
    while(n!=0)
    {
        // if n is even then it will be good to
        // reach n from n/2 by multiplying it by 2.
        if(n%2==0)
            n/=2;
        // if n is odd then we can reach n from n-- only. 
        else
            n--;
        
        count++;     
    }
    return count;

}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	cout<<memo(n)<<endl;
	rep(i,0,n)
	cout<<i<<" : "<<lookup[i]<<endl;


	return 0;
}