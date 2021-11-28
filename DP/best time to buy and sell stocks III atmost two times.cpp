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

/*leetcode solution*/
int maxProfit(vector<int>& prices) {
	if(prices.empty()) return 0;
	int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
        
	for(int i=1;i<prices.size();++i) {            
		s1 = max(s1, -prices[i]);
		s2 = max(s2, s1+prices[i]);
		s3 = max(s3, s2-prices[i]);
		s4 = max(s4, s3+prices[i]);
	}
	return max(0,s4);
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(a)<<endl;

	return 0;
}

