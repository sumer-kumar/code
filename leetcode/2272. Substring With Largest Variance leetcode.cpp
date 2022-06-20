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

//kadane's algorithm
int recur(string &a,char x,char y)
{
	int sm=0;
	int size = a.size();

	int res = 0;

	int fx = 0;
	int fy = 0;

	for(int i=0;i<size;i++)
	{
		if(a[i]==x || a[i]==y)
		{
			fx += a[i]==x?1:0;
			fy += a[i]==y?1:0;

			if(fx<fy)
			fx=fy=0;

			if(fx>0 && fy>0)
			res = max(res,fx-fy);
		}
	}
	return res<0?0:res;
}

int solve(string &a)
{
	int res = 0;

	unordered_set<char> us(a.begin(),a.end());

	string b = a;
	reverse(b.begin(),b.end());

	for(char i='a'; i<='z'; i++)
	{
		if(us.count(i)!=0)
		for(char j='a'; j<='z'; j++)
		{
			if(us.count(j)!=0 && i!=j)
			{
				res = max({res,recur(a,i,j),recur(b,i,j)});
			}
		}
	}

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "lripaa";

    cout<<solve(a)<<endl;

	return 0;
}

