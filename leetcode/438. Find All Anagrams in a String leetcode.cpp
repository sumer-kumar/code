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

int solve(string &a,string &b)
{
	int cnt=0;
	unordered_map<char,int> uma;
	for(char x : a)
		uma[x]++;

	unordered_map<char,int> um;

	int sizeb = b.size();
	int res_size = 0;

	int start=0;

	//window is 'start' to 'i'
	rep(i,0,sizeb-1)
	{
		//if the character does not belong to the string a
		if(uma.count(b[i])==0)
		{
			for(;start<=i;start++)
			{
				if(uma.count(b[start])!=0)
				{
					um[b[start]]--;
				}
			}
			start=i+1;
			res_size=0;
		}
		else
		{
			um[b[i]]++;
			res_size++;

			while(um[b[i]]>uma[b[i]])
			{
				if(uma.count(b[start])!=0)
				{
					res_size--;
					um[b[start]]--;
				}
				start++;
			}
		}

		if(res_size==a.size())
		{
			res_size--;
			um[b[start++]]--;
			cnt++;
		}
	}

	return cnt;
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: s = "cbaebabacd", p = "abc"
Output: [0,6]*/

    string a = "abc";
    string b = "cbaebabacd";

    cout<<solve(a,b)<<endl;

	return 0;
}

