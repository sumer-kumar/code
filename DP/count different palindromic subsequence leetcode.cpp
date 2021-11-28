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


/*









	NOT ABLE TO CODE AND UNDERSTAND THE SOLUTION


	








*/
void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

/*start and end inclusive*/
int recur(string &a,int start,int end)
{	
	if(start>end)
		return 0;
	if(start==end)
		return 1;
	
	if(a[start]==a[end])
		return 1 + recur(a,start+1,end) + recur(a,start,end-1);

	return recur(a,start+1,end) + recur(a,start,end-1);
}

int solve(string &a)
{
	return recur(a,0,a.size()-1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "bccb";
    cout<<solve(s)<<endl;

	return 0;
}

