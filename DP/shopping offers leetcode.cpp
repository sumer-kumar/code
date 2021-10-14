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

/*
	state 0 : buying from special offer
	state 1 : buying from actual prices
*/

bool isValid(vi &need,int curr,vvi &special,vi &res)
{
	int size = need.size();
	rep(i,0,size-1)
	{
		if(need[i]<special[curr][i])
			return false;
	}

	rep(i,0,size-1)
	{
		res.pb(need[i]-special[curr][i]);
	}
	return true;
}

int recur(vi &price,vi &need,vvi &special,int curr,int state)
{
	if(state==0)
	{
		if(curr >= special.size())
		return recur(price,need,special,0,1);

		vi res;
		if(isValid(need,curr,special,res))
		{
			int m1 = special[curr].back()+recur(price,res,special,curr,state);
			int m2 = recur(price,need,special,curr+1,state);

			// cout<<state<<" "<<curr<<" "<<m1<<" "<<m2<<endl;

			return min(m1,m2);
		}
		int m1= recur(price,need,special,curr+1,state);
		// cout<<state<<" "<<curr<<" "<<m1<<" "<<endl;
		return m1;
	}
	else
	{
		if(curr>=price.size())
			return 0;

		int t=0;
		swap(t,need[curr]);
		int m1 = t*price[curr]+recur(price,need,special,curr+1,state);
		// cout<<state<<" "<<curr<<" "<<m1<<endl;
		swap(t,need[curr]);
		return m1;
	}
}


int solve(vi &price,vi &need,vvi &special)
{
	int size = price.size();
	return recur(price,need,special,0,0);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]*/
/*price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]*/

    vi price = {2,5};
    vvi special = {
    	{3,0,5},
    	{1,2,10}
    };
    vi need = {3,2};

    cout<<solve(price,need,special)<<endl;

	return 0;
}

