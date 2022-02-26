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


string solve(string &s,string &t)
{
	sort(s.begin(),s.end());

	if(t!="abc")
		return s;

	int cb=0;
	int cc=0;
	int ca=0;

	for(char x : s)
	{
		if(x=='b')
			cb++;
		else if(x=='c')
			cc++;
		else if(x=='a')
			ca++;
	}

	string res="";
	int size = s.size();

	if(cb==0 || cc==0 || ca==0)
		return s;

	rep(i,0,size-1)
	{
		if(s[i]=='b')
		{
			while(cc>0)
			{
				res.pb('c');
				cc--;
			}
		}
		else if(s[i]=='c')
		{
			while(cb>0)
			{
				res.pb('b');
				cb--;
			}
		}
		else
			res.pb(s[i]);
	}

	return res;
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
    	string s,t;
    	cin>>s>>t;

    	cout<<solve(s,t)<<endl;
    }

	return 0;
}

