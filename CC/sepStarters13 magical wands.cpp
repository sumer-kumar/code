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


int solve(string &a)
{
	int size = a.size();

	bool curr = false;//0

	int count=0;

	rep(i,0,size-1)
	{
		if(a[i]=='1')
		{
			//close
			if(curr^1==0)
			{
				count++;
				curr = !curr;
			}
		}	
		else
		{
			if(curr^0==0)
			{
				count++;
				curr = !curr;
			}
		}
	}

	return count;
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

