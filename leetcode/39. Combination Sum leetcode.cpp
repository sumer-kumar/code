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

void recur(vi &a,int curr,int k,vi &t,set<vi> &st)
{

	if(k<0)
		return;

	if(k==0)
	{
		st.insert(t);
		return;
	}

	if(curr==a.size())
		return ;

	recur(a,curr+1,k,t,st);

	if(a[curr]>k)
		return;

	t.pb(a[curr]);
	recur(a,curr,k-a[curr],t,st);
	recur(a,curr+1,k-a[curr],t,st);
	t.pop_back();

}

vvi solve(vi &a,int k)
{
	sort(a.begin(),a.end());
	set<vi> st;
	vi t;
	recur(a,0,k,t,st);

	vvi res(st.begin(),st.end());

	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]*/

    vi a = {2,3,6,7};
    int k=7;
    vvi res = solve(a,k);

    for(auto x : res)
    {
    	for(int p : x)
    		cout<<p<<" ";
    	cout<<endl;
    }

	return 0;
}

