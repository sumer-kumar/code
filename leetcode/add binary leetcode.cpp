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


string solve(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	if(a.size()<b.size())
		swap(a,b);
	
	int asize = a.size();
	int bsize = b.size();

	rep(i,1,asize-bsize)
	b.pb('0');

	string res = "";
	string carry = "0";

	rep(i,0,asize-1)
	{
		if(a[i]=='1'&& b[i]=='1')
		{
			if(carry=="1")
			{
				res.pb('1');
				carry="1";
			}
			else
			{
				res.pb('0');
				carry="1";
			}
		}
		else if(a[i]=='1' || b[i]=='1')
		{
			if(carry=="1")
			{
				res.pb('0');
				carry="1";
			}
			else
			{
				res.pb('1');
			}
		}
		else
		{
			if(carry=="1")
			{
				res.pb('1');
				carry="0";
			}
			else
			{
				res.pb('0');
			}
		}
	}

	if(carry=="1")
		res.pb('1');

	reverse(res.begin(),res.end());
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "1010";
    string b = "1011";

    cout<<solve(a,b)<<endl;

	return 0;
}

