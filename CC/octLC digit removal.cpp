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


int solve(int n,int d)
{
	string a = to_string(n);

	int size = a.size();

	rep(i,0,size-1)
	{
		// cout<<"ff "<<a<<" "<<i<<endl;
		if(a[i] == '0'+d)
		{	
			int ten_pow = size-i-1;
			
			int t = pow(10,ten_pow);

			int x = stoi(a);

			x += t;

			a = to_string(x);
			
			int size = a.size();
			
			rep(j,i+1,size-1)
			a[j]='0';

			// cout<<a<<" "<<t<<endl;
		}
	}

	cout<<n<<" "<<a<<" "<<d<<" ";

	return stoi(a)-n;
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
    	int n,d;
    	cin>>n>>d;

    	cout<<solve(n,d)<<endl;
    }

	return 0;
}

