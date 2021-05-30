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

bool recur(string a,string b)
{	

	int n = a.size();

	if(n!=b.size())
		return false;


	if(a==b)
		return true;

	if(n<=1)
	 return false; 

	for(int i=1;i<n;i++)
	{
		/*when not swapped*/
		if(recur(a.substr(0,i),b.substr(0,i)) 
			&& recur(a.substr(i,n-1),b.substr(i,n-1)))
			return true;

		/*when swapped*/
		if(recur(a.substr(0,i),b.substr(n-i,i)) 
			&& recur(a.substr(i,n-1),b.substr(0,n-i)))
			return true;		
	}
	return false;
}


/*using memoization*/
unordered_map<string,bool> um;
bool memo(string a,string b)
{	

	int n = a.size();

	if(n!=b.size())
		return false;


	if(a==b)
		return true;

	if(n<=1)
	 return false;

	string key = a + " "+ b;
	if(um.find(key)!=um.end())
		return um[key];

	for(int i=1;i<n;i++)
	{
		/*when not swapped*/
		if(memo(a.substr(0,i),b.substr(0,i)) 
			&& memo(a.substr(i,n-1),b.substr(i,n-1)))
			return um[key]=true;

		/*when swapped*/
		if(memo(a.substr(0,i),b.substr(n-i,i)) 
			&& memo(a.substr(i,n-1),b.substr(0,n-i)))
			return um[key]=true;		
	}
	return um[key] = false;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    um.clear();
    cout<<recur(a,b)<<endl;
    cout<<memo(a,b)<<endl;

	return 0;
}

