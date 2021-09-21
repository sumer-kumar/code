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

string solve(int a,int b,int c,int d,int e)
{
	if(a<=e && b+c<=d)
		return "YES";

	if(b<=e && a+c<=d)
		return "YES";
	
	if(c<=e && b+a<=d)
		return "YES";

	return "NO";
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
    	int a,b,c,d,e;
    	cin>>a>>b>>c>>d>>e;

    	cout<<solve(a,b,c,d,e)<<endl;
    }

	return 0;
}

