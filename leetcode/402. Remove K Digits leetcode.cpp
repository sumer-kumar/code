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

string solve(string &a,int k)
{
	int size = a.size();

	// try to index of find the nearest right element
	vi right(size,0);
	
	right[0]=-1;

	stack<int> st;
	st.push(a[0]);

	rep(i,0,size-1)
	{
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty())
		{
			right[i]=-1;
			st.push(i);
		}
		else
		{
			right[i]=st.top();
			st.push(i);
		}
	}

	for(int x : right)
		cout<<x<<" ";
	cout<<endl;

	rep(i,0,size-1)
	{
		if(right[i]==-1 || a[right[i]]=='#')
			continue;
		a[right[i]]='#';
		right[i]=-1;
		
		k--;
		
		if(k<=0)
			break;
	}

	if(k>0)
	{
		k++;
		int i=size-1;
		while(i>=0 && k--)
		{
			if(a[i]!='#')
				a[i]='#';
			i--;
		}
	}

	//remove leading zeroes
	for(char &x : a)
	{
		if(x=='0')
			x='#';	
		if(x!='0' && x!='#')
			break;
	}	

	string res;

	for(char x : a)
	{
		if(x!='#')
			res.pb(x);
	}

	return res;
}

string solve2(string &a,int k)
{
	string res="";
	for(char &x : a)
	{
		while(res.size() && res.back()>x && k){
			res.pop_back();
			k--;
		}
		if(res.size() || x!='0')
			res.pb(x);
	}

	while(res.size()!=0 && k--)
		res.pop_back();

	return res.size()==0?"0":res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "00192837465";
    int k = 3;

    cout<<solve2(a,k)<<endl;

	return 0;
}

