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

int lps(string a,string b,int &start,int &end)
{
	int aa=a.size();
	
	vvi dp(aa+1,vi(aa+1,0));

	int ans = 0;
	rep(i,0,aa)
	{
		rep(j,0,aa)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
				if(ans<dp[i][j])
				{
					ans = dp[i][j];
					start = i-1;
					end = j-1;
				}
			}
				// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	return ans;
}

bool isPali(string s)
{
	int i=0,j=s.size()-1;
	while(i<=j)
	{
		if(s[i++]!=s[j--])
			return false;
	}
	return true;
}

string solve(string a)
{
	string b = a;
	reverse(b.begin(),b.end());
	int end,start;
	int lp = lps(a,b,end,start);
	cout<<lp<<" "<<end<<" "<<start<<endl;
	start = min(start,end);
	string ans1 = b.substr(a.size()-end-1,lp);
	string ans2 = a.substr(start+1,lp);

	if(ans1.size()<ans2.size())
		swap(ans1,ans2);

	if(isPali(ans1))
		return ans1;
	if(isPali(ans2))
		return ans2;
	return isPali(ans1)?ans1:a.substr(0,1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;

    cout<<solve(a)<<endl;


	return 0;
}

