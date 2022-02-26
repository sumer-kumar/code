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


// int solve(double n)
// {
// 	double a_2 = pow(n,0.5);
// 	double a_3 = pow(n,(double)1/3);

// 	return a_2+a_3-1;
// }
/*
4
1
6
32591
32590
23125
*/

int solve(int n)
{
	set<int> st;
	int t;
	rep(i,1,31622)
	{	
		t = i*i;
		if(t<=n) 
		st.insert(t);
	}
	rep(i,1,1000)
	{
		t = i*i*i;
		if(t<=n)
		st.insert(t);
	}

	return st.size();
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
    	double n;
    	cin>>n;

    	cout<<solve(n)<<endl;
    }

	return 0;
}

