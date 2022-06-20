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


string solve(string &a,string &b,int size)
{
	unordered_map<char,queue<int>> um;

	rep(i,0,size-1)
	um[a[i]].push(i);

	int i=0;
	int j=0;

	vi vis(size,0);

	for(int i=0;i<size;)
	{
		// cout<<i<<" "<<j<<endl;
	
		if(vis[i]==1)
		{
			i++;
			continue;
		}

		// for(int x : vis)
		// 	cout<<x<<" ";
		// cout<<endl;

		if(a[i]==b[j])
		{
			// cout<<"condition1"<<endl;
			um[a[i]].pop();
			vis[i] = 1;
			i++;
		}
		else if(a[i]=='a' && b[j]=='b')
		{
			// cout<<"condition2"<<endl;
			if( (um['b'].empty()) || (!um['c'].empty() && um['c'].front() < um['b'].front()))
				return "NO";
			vis[um['b'].front()] = 1;
			um['b'].pop();
		}
		else if(a[i]=='b' && b[j]=='c')
		{
			// cout<<"condition3"<<endl;
			if( (um['c'].empty()) || (!um['a'].empty() && um['a'].front() < um['c'].front()))
				return "NO";
			vis[um['c'].front()] = 1;
			um['c'].pop();
		}
		else
		{
			// cout<<"condition4"<<endl;
			return "NO";
		}
		// for(int x : vis)
		// 	cout<<x<<" ";
		// cout<<endl;		
		j++;
	}
	return "YES";
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
    	int n;
    	cin>>n;
    	string a,b;
    	cin>>a>>b;

    	cout<<solve(a,b,n)<<endl;
    }

	return 0;
}

