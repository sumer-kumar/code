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

bool isabc(stack<char> &st)
{
	if(st.size()<3)
		return false;

	char p = st.top();
	st.pop();

	char q = st.top();
	st.pop();

	char r = st.top();
	st.pop();

	if(p=='c' && q=='b' && r=='a')
		return true;

	st.push(r);
	st.push(q);
	st.push(p);
	return false;
}


bool solve(string &s)
{
	stack<char> st;

	int size = s.size();

	if(size%3!=0)
		return false;

	rep(i,0,size-1)
	{
		st.push(s[i]);

		isabc(st);
	}	

	while(!st.empty() && isabc(st))
	{}

	return st.empty()?true:false;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: s = "aabcbc"
Output: true*/

    string s = "aabcbc";
    cout<<solve(s)<<endl;

	return 0;
}

