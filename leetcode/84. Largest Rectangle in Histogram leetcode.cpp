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

void print(vi &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
}

int solve(vi &a)
{
	int size=a.size();

	stack<int> st;

	vi left(size,0),right(size,0);

	//for left
	for(int i=0;i<size;i++)
	{
		while(!st.empty() && a[st.top()]>=a[i])
			st.pop();
		if(st.empty())
			left[i]=-1;
		else
			left[i]=st.top();
		st.push(i);
	}

	while(!st.empty())
		st.pop();

	//for right
	for(int i=size-1;i>=0;i--)
	{
		while(!st.empty() && a[st.top()]>=a[i])
			st.pop();
		if(st.empty())
			right[i]=size;
		else
			right[i]=st.top();
		st.push(i);
	}

	print(left);
	print(right);

	int mx=0;

	for(int i=0;i<size;i++)
	{
		int area = a[i]*(right[i]-left[i]-1);
		mx=max(mx,area);
	}


	return mx;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: heights = [2,1,5,6,2,3]
Output: 10*/

    vi a = {1,1};
    cout<<solve(a)<<endl;

	return 0;
}

