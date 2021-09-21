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
void ininarr(int a[],int size);
void ininvi(vi &a,int size=0);
void inllarr(ll a[],ll n);
void inllvi(vll &a,ll size=0);




void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
class Solution {
public:
    int dp[1001][51];
    int n;
    int helper(int i,int m,vector<int>& nums){
        if(i==n)
            return 0;
        if(dp[i][m]!=-1)
            return dp[i][m];
        int ans=1e9,s=0;
        if(m==1){
            for(int j=i;j<n;j++){
                s+=nums[j];
            }
            return dp[i][m]=s;
        }
        for(int j=i;j<n-m+1;j++){
            s+=nums[j];
            ans=min(ans,max(helper(j+1,m-1,nums),s));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return helper(0,m,nums);
    }
};

int recur(vi &a,int start,int k,int max_sum)
{
	int size = a.size();

	if(k==1){
		int t_sum = 0;
		//for the last segment
		for(int i=start;i<a.size();i++)
		{
			t_sum += a[i];
		}
		cout<<max_sum<<" "<<t_sum<<" "<<start<<endl;
		return max(max_sum,t_sum);
	}

	int curr_sum =0;

	int ans = INT_MAX;

	for(int i=start;i<size-k+1;i++)
	{
		curr_sum += a[i];
		ans = min(ans,recur(a,i+1,k-1,max(max_sum,curr_sum)));
	}

	return ans;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    ininvi(a);

    int k;
    cin>>k;
    cout<<recur(a,0,k,0);
	return 0;
}







/******INPUT THINGS*********/
void ininarr(int a[],int size)
{
	rep(i,0,size-1)
	{
		cin>>a[i];
	}
}

void ininvi(vi &a,int size)
{
	if(!size)
		size = a.size();
	rep(i,0,size-1)
	cin>>a[i];
}

void inllarr(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cin>>a[i];
}

void inllvi(vll &a,ll size)
{
	if(!size)
		size=a.size();
	for(ll i=0;i<size;i++)
		cin>>a[i];
}