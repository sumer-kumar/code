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

#define MAX 1000000


int recur1(vector<char> &a,vector<char> &b)
{
	int _10 = 0;
	int _01 = 0;

	int size = a.size();

	rep(i,0,size-1)
	{
		if(a[i]=='0' && b[i]=='1')
			_01++;
		else if(a[i]=='1' && b[i]=='0')
			_10++;
	}
	// cout<<_10<<" "<<_01<<endl;
	return _10!=_01 ?MAX:2*_01;
}

int recur2(vector<char> a,vector<char> b)
{
	int size = a.size();
	int ind=-1;

	rep(i,0,size-1)
	{
		if(a[i]=='1' && b[i]=='0'){
			ind=i;
			break;
		}
	}
	
	if(ind==-1)
		return MAX;

	rep(i,0,size-1)
	{
		if(i==ind)
			continue;
		a[i] = a[i]=='1'?'0':'1';
	}

	return recur1(a,b);
}

int recur3(vector<char> a,vector<char> b)
{
	int size = a.size();
	int ind=-1;

	rep(i,0,size-1)
	{
		if(a[i]=='1' && b[i]=='1'){
			ind=i;
			break;
		}
	}
	
	if(ind==-1)
		return MAX;

	rep(i,0,size-1)
	{
		if(i==ind)
			continue;
		a[i] = a[i]=='1'?'0':'1';
	}

	return recur1(a,b);
}

int solve(vector<char> &a,vector<char> &b)
{
	int size = a.size();

	// cout<<recur1(a,b)<<"--"<<1+recur2(a,b)<<"--"<<1+recur3(a,b)<<endl;

	int mn = min({recur1(a,b),1+recur2(a,b),1+recur3(a,b)}); 
	return mn>=MAX?-1:mn;
}
/*
0
1
-1
3
4
*/

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
    	vector<char> a(n),b(n);

    	rep(i,0,n-1) cin>>a[i];
    	rep(i,0,n-1) cin>>b[i];

    	cout<<solve(a,b)<<endl;
    }

	return 0;
}

