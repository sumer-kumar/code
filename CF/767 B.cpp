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


string solve(int l,int r,int k)
{
	if(l==r)
		return l==1?"No":"Yes";

	int odd=0;

	int len = r-l+1;
	if(len%2==0)
		odd=len/2;
	else
	{
		if(r%2==0)
			odd=len/2;
		else
			odd=len/2+1;
	}

	return odd<=k?"Yes":"No";
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
	    int l,r,k;
	    cin>>l>>r>>k;

	    cout<<solve(l,r,k)<<endl;    	
    }


	return 0;
}

