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
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int main(){
	fastio;
	defile();

	int tests;
	cin >> tests;

	while(tests--){

		int n;
		cin >> n;
		string s[n];
		string ans;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			if(s[i][i]=='0') ans += '1';
			else if(s[i][i]=='1') ans += '0';
		}
		cout << ans << endl;
	}
	
	

	return 0;
}