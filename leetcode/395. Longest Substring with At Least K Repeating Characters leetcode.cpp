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


//i and j are first and last index inclusive
int recur(string &a,int start,int end,int k)
{
	if(end-start+1<k)
		return 0;

	unordered_map<char,vector<int>> um;

    for(int i=start;i<=end;i++)
	{
		um[a[i]].push_back(i);
	}

	vector<int> temp={-1};

	for(auto x : um)
	{
		if(x.second.size()<k)
		{
			for(int p : x.second)
				temp.push_back(p);
		}
	}

	sort(temp.begin(),temp.end());
	if(temp.size()-1==0)
		return end-start+1;

	int mx = 0;

	temp.push_back(end+1);

	//divide the string to the adjacents
	for(int i=1;i<temp.size();i++)
	{
		mx = max(mx,recur(a,temp[i-1]+1,temp[i]-1,k));
	}

	return mx;
}

int solve(string &a,int k)
{
	int size = a.size();

	return recur(a,0,a.size()-1,k);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   /*Input: s = "ababbc", k = 2
Output: 5*/
    /*"bbaaacbd"
		3
		op=3*/

    string a = "ababbc";
    int k=2;

    cout<<solve(a,k)<<endl;

	return 0;
}

/*

we will store the index of each character in unordered_map<char,vector<int>> 
check the size of each key if it is less than k than push it into the temp vector

sort the temp vector

push -1 to start of vector and "end+1" to the end of the vector to take care of the corner cases

split the string into parts from traversing the temp vector 

you will understand more when you see the code

*/