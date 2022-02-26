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

void recur(vi &a,int i,string op = "")
{
	if(i>=a.size())
	{
		cout<<op<<endl;
		return;
	}
	recur(a,i+1,op);
	recur(a,i+1,op+" "+to_string(a[i]));
}

void solve(vi &a)
{
	int size = a.size();

	rep(i,0,(1<<size)-1)
	{
		int t=i;
		int j=0;
		while(t>0)
		{
			if(t&1)
			{
				cout<<a[j]<<" ";
			}
			t = t>>1;
			j++;
		}
		cout<<endl;
	}
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vi a = {1,2,3};

    // solve(a);
    recur(a,0,"-");


	return 0;
}

