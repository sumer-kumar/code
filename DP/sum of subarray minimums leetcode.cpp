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


int solve(vector<int>& A) {
	stack<pair<int, int>> in_stk_p, in_stk_n;
	// left is for the distance to previous less element
	// right is for the distance to next less element
	vector<int> left(A.size()), right(A.size());
		
	//initialize
	for(int i = 0; i < A.size(); i++) left[i] =  i + 1;
	for(int i = 0; i < A.size(); i++) right[i] = A.size() - i;
		
	for(int i = 0; i < A.size(); i++){
	  // for previous less
		while(!in_stk_p.empty() && in_stk_p.top().first > A[i]) in_stk_p.pop();
		left[i] = in_stk_p.empty()? i + 1: i - in_stk_p.top().second;
		in_stk_p.push({A[i],i});
			
		// for next less
		while(!in_stk_n.empty() && in_stk_n.top().first > A[i]){
		auto x = in_stk_n.top();in_stk_n.pop();
		right[x.second] = i - x.second;
		
		}
	    in_stk_n.push({A[i], i});
	}

	int ans = 0, mod = 1e9 +7;
	for(int i = 0; i < A.size(); i++){
	  ans = (ans + A[i]*left[i]*right[i])%mod;
	}
	return ans;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {3,1,2,4};

    cout<<solve(a)<<endl;

	return 0;
}

