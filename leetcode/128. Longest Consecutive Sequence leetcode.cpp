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
	int size = a.size();

	if(size==0)
		return 0;

	unordered_set<int> st(a.begin(),a.end());

	int mx=1;

	for(int x : a)
	{
		//check if x is the beggining of the sequence
		if(st.count(x-1)==0)
		{
			int curr_mx = 1;
			int curr = x;

			while(st.count(curr+1)!=0)
			{
				curr++;
				curr_mx++;
			}
			mx = max(mx,curr_mx);
		}
	}

	return mx;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	/*Input: nums = [100,4,200,1,3,2]
	Output: 4*/

	vi a = {100,4,200,1,3,2};

	cout<<solve(a)<<endl;    

	return 0;
}

