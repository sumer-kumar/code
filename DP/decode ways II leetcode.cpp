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

int recur(string &a,int curr)
{

	if(curr==a.size())
		return 1;

	if(curr>a.size())
		return 0;

	if(a[curr]=='0')
		return 0;

	if(a[curr]=='*')
	{
		
		return res;
	}
	else
	{
		if(a[curr]=='1' and curr+1<a.size() and a[curr+1]=='*')
			return recur(a,curr+1);

		if(a[curr]=='1')
			return recur(a,curr+1) + recur(a,curr+2);

		if(a[curr]=='2')
		{
			if(curr+1<a.size() && a[curr+1]>='0' && a[curr+1]<='6')
				return recur(a,curr+1) + recur(a,curr+2);
		}

		return recur(a,curr+1);
	}
}

int solve(string a)
{
	return recur(a,0);
}

/*

java leetcode solution
public class Solution {
    int M = 1000000007;
    public int numDecodings(String s) {
        Long[] memo = new Long[s.length()];
        return (int) ways(s, s.length() - 1, memo);
    }
    public long ways(String s, int i, Long[] memo) {
        if (i < 0)
            return 1;
        if (memo[i] != null)
            return memo[i];
        if (s.charAt(i) == '*') {
            long res = 9 * ways(s, i - 1, memo) % M;
            if (i > 0 && s.charAt(i - 1) == '1')
                res = (res + 9 * ways(s, i - 2, memo)) % M;
            else if (i > 0 && s.charAt(i - 1) == '2')
                res = (res + 6 * ways(s, i - 2, memo)) % M;
            else if (i > 0 && s.charAt(i - 1) == '*')
                res = (res + 15 * ways(s, i - 2, memo)) % M;
            memo[i] = res;
            return memo[i];
        }
        long res = s.charAt(i) != '0' ? ways(s, i - 1, memo) : 0;
        if (i > 0 && s.charAt(i - 1) == '1')
            res = (res + ways(s, i - 2, memo)) % M;
        else if (i > 0 && s.charAt(i - 1) == '2' && s.charAt(i) <= '6')
            res = (res + ways(s, i - 2, memo)) % M;
        else if (i > 0 && s.charAt(i - 1) == '*')
            res = (res + (s.charAt(i) <= '6' ? 2 : 1) * ways(s, i - 2, memo)) % M;
        memo[i] = res;
        return memo[i];
    }
}

*/

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "**";
    cout<<solve(a)<<endl;

	return 0;
}

