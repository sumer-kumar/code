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

// unordered_map<int,vi> um;
// void recur(vi &a,int curr,int size,vi &t,vi &res)
// {

// 	// cout<<curr<<" "<<res.size()<<endl;
// 	if(curr>=size)
// 	{
// 		if(t.size()>res.size())
// 		{
// 			res = t;
// 		}
// 		return ;
// 	}

// 	//choose current element of a
// 	//t having a previous element
// 	if(t.size()>0)
// 	{
// 		//if feasible
// 		if(a[curr]%t.back()==0)
// 		{
// 			t.pb(a[curr]);
// 			recur(a,curr+1,size,t,res);
// 			t.pop_back();
// 		}
// 	}

// 	recur(a,curr+1,size,t,res);
// }

// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const
//     {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };


// string getHash(int a,int b,int c)
// {
// 	return to_string(a)+" "+to_string(b)+" "+to_string(c);
// }

// unordered_map<string,vi> um;
// vi recur(vi &a,int curr,int last,vi &t,int size)
// {

// 	// cout<<curr<<" "<<last<<endl;
// 	// for(int x : t)
// 	// 	cout<<x<<" ";
// 	// cout<<"\n\n";

// 	vi inc;
// 	vi exc;

// 	if(curr>=size)
// 		return t;

	
// 	if(um.find(getHash(curr,last,t.size()))!=um.end())
// 		return um[getHash(curr,last,t.size())];

// 	if(a[curr]%last==0)
// 	{
// 		t.pb(a[curr]);
// 		inc = recur(a,curr+1,a[curr],t,size);
// 		t.pop_back();
// 	}

// 	exc = recur(a,curr+1,last,t,size);

// 	return um[getHash(curr,last,t.size())] = inc.size()>exc.size()?inc:exc;

// }


void solve(vi &a)
{
/*	um.clear();
	sort(a.begin(),a.end());
	for(int x : a)
		cout<<x<<" ";
	cout<<endl;
	int size = a.size();

	vi t;

	vi res = recur(a,0,1,t,size);

	for(int x : res)
		cout<<x<<" ";
	cout<<endl;*/


	int size = a.size();

	sort(a.begin(),a.end());

	vi dp(size+1,0);

	int mx = 0;

	rep(i,1,size-1)
	{
		rep(j,0,i-1)
		{
			if(a[i]%a[j]==0)
			{
				dp[i] = max(dp[i],dp[j]+1);
			}
		}

		mx = max(mx,dp[i]);
	}

	rep(i,0,size-1)
	{
		if(dp[i]==mx)
		{
			mx = i;
			break;
		}
	}

	// cout<<mx<<endl;

	vi res;

	res.pb(a[mx]);

	for(int i=mx-1;i>=0;i--)
	{
		if(dp[mx]-1 == dp[i] && a[mx]%a[i]==0)
		{
			res.pb(a[i]);
			mx=i;
		}
	}

	for(int x : res)
		cout<<x<<" ";
	cout<<endl;



	// return res;

}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {5, 9, 18, 54, 90 ,108, 180, 360, 540, 720 };

    solve(a);

	return 0;
}

