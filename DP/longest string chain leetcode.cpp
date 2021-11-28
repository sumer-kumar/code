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
	the question is a lot lot similar to longest increasing subsequence
	-> first we will sort the string array according to the length of the string 
	-> we will first work try to remove one character at a time 
	-> and then check if it is present before that index or not
	-> if it is present we will record the longest chain ending with that string
	-> and more you will get from the code
*/

// static
bool cmp(const string &a,const string &b)
{
	return a.size()<b.size();
}

int solve(vector<string> &a)
{
	//sort w.r.t the length of the string 
	sort(a.begin(),a.end(),cmp);

	unordered_map<string,int> um;

	int res = 1;

	//pick one word at one time from starting index
	for(string x : a)
	{
		//now traverse through the array
		int size = x.size();
			
		//hash with length one in starting
		um[x] = 1;

		for(int i=0;i<size;i++)
		{
			string t = x.substr(0,i)+x.substr(i+1);
			if(um.find(t)!=um.end())
			{
				um[x] = max(um[x],1+um[t]);
			}
		}
		res = max(res,um[x]);
	}
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    cout<<solve(a)<<endl;

	return 0;
}

