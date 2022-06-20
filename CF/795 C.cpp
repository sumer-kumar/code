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

ll calculate(string &a)
{
	int size = a.size();
	ll sm = 0;
	rep(i,0,size-2)
	{
		if(a[i]=='1' && a[i+1]=='0')
			sm += 10;
		else if(a[i]=='1' && a[i+1]=='1')
			sm += 11;
		else if(a[i]=='0' && a[i+1]=='1')
			sm += 1;
	}
	return sm;
}

ll solve(string &a,int size,int k)
{
	deque<int> dq;
	rep(i,0,size-1){
		if(a[i]=='1')
		{
			dq.push_back(i);
		}
	}
	
	if(a.back()=='1' && a[0]=='1')
		return calculate(a);

	if(!dq.empty() && a.back()=='0' && (size-1)-dq.back()<=k)
	{
		k-=(size-1)-dq.back();
		swap(a[size-1],a[dq.back()]);
		dq.pop_back();
	}
	if(!dq.empty() && dq.back()==size-1)
		dq.pop_back();

	if(!dq.empty() && a[0]=='0' && dq.front()<=k)
	{
		swap(a[0],a[dq.front()]);
		dq.pop_front();
	}

	return calculate(a);
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
    	int n,k;
    	cin>>n>>k;

    	string a;
    	cin>>a;

    	cout<<solve(a,n,k)<<endl;
    }


	return 0;
}

