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
	part1_sum/p1_count = t_sum/total_count;
	t_sum = (part1_sum*total_count)/p1_count;
*/

/*this gives MLE*/

string getHash(int curr,int curr_sum,int count)
{
	return to_string(curr)+" "+to_string(curr_sum)+" "+to_string(count);
}

unordered_map<string,bool> um;
bool recur(vi &a,int curr,int curr_sum,int count,int t_sum)
{
	if(curr==a.size())
	{
		if(count>0 && count<a.size() && (double)t_sum==((double)curr_sum*a.size())/count)
			return true;
		
		return false;
	}

	string hsh = getHash(curr,curr_sum,count);

	if(um.find(hsh)!=um.end())
		return um[hsh];

	return um[hsh] = recur(a,curr+1,curr_sum+a[curr],count+1,t_sum) || 
		   recur(a,curr+1,curr_sum,count,t_sum);
}

int solve(vi &a)
{
	if(a.size()==1)
		return false;
	um.clear();
	int sum = 0;
	for(int &x : a)
		sum += x;
	return recur(a,0,0,0,sum);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [1,2,3,4,5,6,7,8]
		Output: true
	[6,8,18,3,1]:false*/

    vi a = {1,2,3,4,5,6,7,8};

    cout<<solve(a)<<endl;

	return 0;
}

