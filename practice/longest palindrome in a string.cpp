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

vector<int> single_point_expansion(string &a,int curr)
{
	int size = a.size();
	int start = curr;
	int end = curr;

	while(start>=0 && end<size)
	{
		if(a[start]!=a[end])
			return {start+1,end-1};
		start--;
		end++;
	}

	return {start+1,end-1};
}

//double point expansion
vector<int> double_point_expansion(string &a,int start,int end)
{
	int size = a.size();

	while(start>=0 && end<size)
	{
		if(a[start]!=a[end])
			return {start+1,end-1};
		start--;
		end++;
	}

	return {start+1,end-1};
}

string solve(string &a)
{
	int size = a.size();
	
	int start = 0;
	int end = 0;

	//single point expansion
	for(int i=1;i<size-1;i++)
	{
		vector<int> t = single_point_expansion(a,i);
		if(t[1]-t[0]>end-start)
		{
			start = t[0];
			end = t[1];
		}
	}

	for(int i=0;i<size-1;i++)
	{	
		if(a[i]==a[i+1])
		{
			vector<int> t = double_point_expansion(a,i,i+1);
			if(t[1]-t[0]>end-start)
			{
				start = t[0];
				end = t[1];
			}			
		}
	}

	return a.substr(start,end-start+1);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	// 01234567
    /*S = "aaaabbaa"*/
    string a = "qrrc";

    cout<<solve(a)<<endl;

	return 0;
}

