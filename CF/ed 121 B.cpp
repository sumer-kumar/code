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


string solve(string &a)
{
	int size = a.size();
	for(int i=size-1;i>0;i--)
	{
		int x = a[i]-'0';
		int y = a[i-1]-'0';

		int ans = x+y;
		if(x+y>9)
		{
			return a.substr(0,i-1)+to_string(ans)+a.substr(i+1);
		}
	}

	int x = a[0]-'0';
	int y = a[1]-'0';

	int ans = x+y;

	return to_string(ans)+a.substr(2);
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
    	string a;
    	cin>>a;

    	cout<<solve(a)<<endl;
    }

	return 0;
}

