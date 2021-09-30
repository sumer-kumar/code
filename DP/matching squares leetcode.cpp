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


bool recur(vi &a,int curr,int p1,int p2,int p3,int p4)
{

	if(curr==a.size() && p1==0 && p2==0 && p3==0 && p4==0)
		return true;

	if(curr==a.size())
		return false;

	if(p1-a[curr]>=0 && recur(a,curr+1,p1-a[curr],p2,p3,p4))
		return true;

	if(p2-a[curr]>=0 && recur(a,curr+1,p1,p2-a[curr],p3,p4))
		return true;

	if(p3-a[curr]>=0 && recur(a,curr+1,p1,p2,p3-a[curr],p4))
		return true;

	if(p4-a[curr]>=0 && recur(a,curr+1,p1,p2,p3,p4-a[curr]))
		return true;

	return false;
}

bool solve(vi &a)
{
	int sum =0;

	int size = a.size();

	for(int x : a)
		sum += x;

	if(size<4 || sum%4!=0)
		return false;

	sort(a.begin(),a.end(),greater<int>());

	int mx = sum/4;

	return recur(a,0,mx,mx,mx,mx);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {3,3,3,3,4};

    cout<<solve(a)<<endl;

	return 0;
}

