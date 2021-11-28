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
/**************************TLE ON GFG**************************/
void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

bool isPali(string &s,int i,int j)
{
	if(i==j)
		return true;
	return s[i]==s[j]?isPali(s,i+1,j-1):false;
}

/*recursive*/
int recur(string &s,int i,int j)
{	
	if(i>j)
		return 0;
	if(isPali(s,i,j))
		return 0;
	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		int t = recur(s,i,k)+recur(s,k+1,j)+1;
		ans = min(ans,t);
	}
	return ans;
}

/*memoization*/
vvi dp(1001,vi(1001,-1));
int solve(string &s,int i,int j)
{
	if(i>j)
		return 0;
	
	if(isPali(s,i,j))
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans = INT_MAX;
	rep(k,i,j-1)
	{
		// int t = recur(s,i,k)+recur(s,k+1,j)+1;
		int r,l;
		if(dp[i][k]!=-1)
			r=dp[i][k];
		else
			r=solve(s,i,k);

		if(dp[k+1][j]!=-1)
			l=dp[k+1][j];
		else 
			l=solve(s,k+1,j);

		ans = min(ans,l+r+1);
	}
	return dp[i][j] = ans;
}

/*leetcode c++ code*/
/*
class Solution {
public:

int dp[2001], palin[2001][2001];

bool check(string &s, int low, int high)
{
    if(low >= high)
        return true;
    
    if(palin[low][high] != -1)
        return palin[low][high];
    
    return palin[low][high] = (s[low] == s[high]) && check(s, low+1, high-1);
}

int help(string &s, int index)
{
    int size = s.size();
    if(size == index)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];
    
    int ans = 2001;
    for(int i=index; i<size; i++)
    {
        if(check(s, index, i))
            ans = min(ans, 1 + help(s, i+1));
    }
    
    return dp[index] = ans;
}

int minCut(string &s) {
    
    memset(dp, -1, sizeof(dp));
    memset(palin, -1, sizeof(palin));
    return help(s, 0)-1;
}
};
*/

/*leetcode java solution*/
/*
class Solution {
    private Integer dp[][];
    private Boolean dpIsPalindrome[][];
    public int minCut(String s) {
        dp = new Integer[s.length()][s.length()];
        dpIsPalindrome = new Boolean[s.length()][s.length()];
        return minCutFrom(s, 0, s.length() - 1);
    }
    
    private int minCutFrom(String s, int start, int end) {
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        
        if (dp[start][end] != null)
            return dp[start][end];
        
        int minCut = s.length() - 1;
        for (int i = start; i <= end; i++) {
            if (isPalindrome(s, start, i)) {
                minCut = Math.min(minCut, 1 + minCutFrom(s, i + 1, end));
            }
        }
        return dp[start][end] = minCut;
    }
    
    private boolean isPalindrome(String s, int start, int end) {
        if (start >= end)
            return true;
        
        if (dpIsPalindrome[start][end] != null)
            return dpIsPalindrome[start][end];
        
        return dpIsPalindrome[start][end] = (s.charAt(start) == s.charAt(end))
            && isPalindrome(s, start + 1, end - 1);
    }
}

*/


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;

    cout<<"bang"<<endl;
    cout<<recur(s,0,s.size()-1)<<endl;
    cout<<solve(s,0,s.size()-1)<<endl;

    rep(i,0,s.size())
    {
    	rep(j,0,s.size())
    	cout<<dp[i][j]<<" ";
    	cout<<endl;
    }

	return 0;
}

