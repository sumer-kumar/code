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

bool isPali(int a,int b)
{
	string aa = (a<=9?"0":"") + to_string(a);
	string bb =(b<=9?"0":"") + to_string(b);
	// cout<<aa<<" "<<bb<<endl;

	return ((aa[0] == bb[1]) && (aa[1]==bb[0])?true:false);
}

int solve(string &a,int time)
{
	unordered_set<string> us;
	string curr = a;
	int cnt = 0;
	int h = stoi(curr.substr(0,2));
	int m = stoi(curr.substr(3,2));
	curr = to_string(h) + ":" + to_string(m);

	while(us.count(curr)==0)
	{
		us.insert(curr);
		// cout<<h<<" "<<m<<endl;
		cnt += isPali(h,m);

		// cout<<((h + time/60)%24)<<endl;
		// cout<<((m + time%60)%60)<<endl;
		h = (h + time/60)%24;
		if((m + time%60) >= 60)
		{
			h++;
		h%=24;
		}
		m = (m + time%60)%60;

		curr = to_string(h) + ":" + to_string(m);

	}

	return cnt;
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
    	string a;
    	int time;
    	cin>>a;
    	cin>>time;

    	cout<<solve(a,time)<<endl;
    }

	return 0;
}

