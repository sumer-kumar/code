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


bool check(unordered_set<string> &st,string a)
{
	unordered_map<char,int> um;
	for(char x : a)
	um[x]++; 
	
	int size=a.size();

	for(int i=0;i<size;i++)
	{
		if(um[a[i]]==1)
		{
			string t = a.substr(0,i)+a.substr(i+1);
			// cout<<t<<endl;
			if(st.find(t)!=st.end())
			{
				return true;
			}	
		}
	}
	return false;
}

int solve(vector<string> &a,vector<string> &b)
{
	unordered_set<string> st;
	int size = a.size();

	rep(i,0,size-1)
	{
		string t=a[i];
		sort(t.begin(),t.end());
		st.insert(t);
	}
	int cnt=0;
	size=b.size();
	rep(i,0,size-1)
	{
		string t = b[i];
		sort(t.begin(),t.end());
		if(check(st,t)==true)
		{
			cnt++;
			// cout<<t<<endl;
		}
	}
	return cnt;	
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a = {"ant","act","tack"};
    vector<string> b = {"tack","act","acti"};

    cout<<solve(a,b)<<endl;

	return 0;
}

