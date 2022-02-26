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

string solve(string &a)
{
	vector<string> res;
	string t = "";

	int size = a.size();

	for(int i=0;i<size;i++)
	{
		if(a[i]==' ')
		{
			res.pb(t);
			t = "";
		}
		else
		{
			t.pb(a[i]);	
		}
	}

	if(t.size()>0)
		res.pb(t);

	size = res.size();

	string ans = "";

	for(int i=0;i<size;i++)
	{
		if(res[i].size()>2)
		{
			for(char &x : res[i])
			{
				if(x>='A' && x<='Z')
					x = x+32;
			}
			if(res[i][0]>='a' && res[i][0]<='z')
				res[i][0] = res[i][0]-32;
		}
		else
		{
			for(char &x : res[i])
			{
				if(x>='A' && x<= 'Z')
					x = x+32;
			}
		}
	}

	for(auto x : res)
		ans += x+" ";

	ans.pop_back();

	return ans;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "capiTalIze tH titLe";

    cout<<solve(a)<<endl;

	return 0;
}

