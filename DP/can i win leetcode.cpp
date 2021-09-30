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


/*
	state 0 : first players turn
	state 1 : second players turn
*/


unordered_map<string,bool> um;
bool recur(string &a,int d,bool state)
{

	cout<<a<<" "<<d<<" "<<state<<endl;
	/*base condition*/
	if(d<=0)
	{
		/*first players turn*/
		if(state==false)
		{
			return false;
		}
		/*second players turn */
		else
		{
			return true;
		}
	}


	if(um.find(a)!=um.end())
	{
		return um[a];
	}


	int size = a.size();

	if(state==true)
	{
		int mx=0;
		
		rep(i,1,size)
		{
			if(a[i]=='0')
				mx = max(mx,i);
		}
	
		if(mx>=d)
			return um[a]=false;
	}
	rep(i,1,size)
	{
		/*if element is not used*/
		if(a[i]=='0')
		{
			a[i]='1';
			cout<<i<<" ";
			if(recur(a,d-i,!state))
			{
				return um[a]=true;
			}

			a[i]='0';
		}
	}

	return um[a]=false;

}


bool solve(int n,int d)
{
	int sum = ((n+1)*n)/2;

	if(d>sum)
		return false;
	if(d<=0)
		return true;

	string a="";

	rep(i,0,n)
	a.pb('0');

	return recur(a,d,0);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=10;
    int d=40;

    cout<<solve(n,d)<<endl;

	return 0;
}

