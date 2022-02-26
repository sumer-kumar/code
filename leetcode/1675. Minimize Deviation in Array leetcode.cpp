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

int solve(vi &a)
{
	set<int> st(a.begin(),a.end());

	//increasing the minimum if possible
	while(1)
	{
		//if it is odd
		if((*st.begin())&1)
		{
			int t = *st.begin();
			st.erase(st.begin());

			st.insert(t*2);
		}
		else
			break;
	}


	int min_diff=INT_MAX;

	//decrease the maximum
	while(1)
	{
		min_diff=min(min_diff,*st.rbegin()-*st.begin());
		//if last element is even
		int last = *st.rbegin();
		if(last%2==0)
		{
			int t = *st.rbegin();
				
			st.erase(--st.end());
			st.insert(t/2);
		}
		else
			break;
		
	}

	return min_diff;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1,2,4,5,20};

    cout<<solve(a)<<endl;

	return 0;
}

