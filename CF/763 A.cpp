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


int solve(int r,int c,int rb,int cb,int rd,int cd)
{
	int dr = 1;
	int dc = 1;

	int cnt = 0;

	// cout<<r<<" "<<c<<" "<<rb<<" "<<cb<<' '<<rd<<' '<<cd<<endl;

	while(1)
	{
		// cout<<rb<<" "<<cb<<" : "<<rd<<" "<<cd<<endl;
		if(rb==rd||cb==cd)
			return cnt;

		if(rb+dr>r || rb+dr<1)
			dr = -dr;

		if(cb+dc>c || cb+dc<1)
			dc = -dc;

		rb = rb+dr;
		cb = cb+dc;
		cnt++;
	}

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
    	int r,c;
    	cin>>r>>c;
    	int rb,cb,rd,cd;
    	cin>>rb>>cb>>rd>>cd;

    	cout<<solve(r,c,rb,cb,rd,cd)<<endl;
    }

	return 0;
}

