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

int recur()
{
	
}

int solve(vi &a)
{
	int size = a.size();

	if(size<=1)
		return size;

	vi dp(size,1);
	vi cnt(size,1);
	int mx = 0;
	rep(i,1,size-1)
	{
		rep(j,0,i-1)
		{
			if(a[i]>a[j])
			{
				if(1+dp[j]>dp[i])
				{
					dp[i]=1+dp[j];
					cnt[i]=cnt[j];
				}
				else if(dp[i]=1+dp[j])
				{
					cnt[i]+=cnt[j];
				}
			}
		}
		mx=max(mx,dp[i]);
	}

	int count=0;
	rep(i,0,size-1)
	if(dp[i]==mx) 
		count+=cnt[i];

	return count;  
}

/*leetcode solution*/
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxlen = 1, ans = 0;
        vector<int> cnt(n, 1), len(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j]+1 > len[i]) {
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (len[j]+1 == len[i]) 
                        cnt[i] += cnt[j];
                }
            }
            maxlen = max(maxlen, len[i]);
        }
        // find the longest increasing subsequence of the whole sequence
       // sum valid counts
        for (int i = 0; i < n; i++) 
            if (len[i] == maxlen) ans += cnt[i];
        return ans;
    }

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1};

    cout<<solve(a)<<endl;

	return 0;
}

