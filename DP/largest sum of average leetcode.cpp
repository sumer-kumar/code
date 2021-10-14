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

double avg(vi &sum,int start,int end)
{
	start++;
	end++;
	double t = (sum[end]*1.0-sum[start-1]*1.0)/(end-start+1)*1.0;
	// cout<<(start-1)<<" "<<(end-1)<<" "<<t<<endl;
	return t;
}

double dp[111][111];
double recur(vi &a,vi &sum,int start,int end,int k)
{
	if(start==end)
		return a[start];

	if(k==1)
	{
		return avg(sum,start,end);
	}

	if(dp[start][k]!=-1)
		return dp[start][k];

	double res = 0.0;
	rep(i,start+1,end-k+2)
	{
		double m1 = avg(sum,start,i-1);
		double m2 = recur(a,sum,i,end,k-1);

		res = max(res,m1+m2);
	}

	return dp[start][k] = res;
}

double solve(vi &a,int k)
{
	for(auto &x : dp)
	{
		for(double &p : x)
			p=-1.0;
	}

	int size = a.size();	
	vi sum(size+1,0);
	sum[0]=0;
	rep(i,1,size)
	{
		sum[i] += sum[i-1]+a[i-1];
	}

	return recur(a,sum,0,size-1,k);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*nums = [9,1,2,3,9], k = 3*/
    vi a = {1,2,3,4,5,6,7};
    int k = 4;

    cout<<solve(a,k)<<endl;

	return 0;
}
