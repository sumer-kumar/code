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
typedef vector<vc> vvc;
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

#define size 9

bool row_checker(vvc &a,int r)
{
	vi cnt(size+1,0);
	rep(i,0,size-1)
	{
		if(a[r][i]=='.')
			continue;
		int t = a[r][i]-'1';
		cnt[t]++;
		if(cnt[t]>1)
			return false;
	}

	return true;
}

bool column_checker(vvc &a,int c)
{
	vi cnt(size+1,0);
	rep(i,0,size-1)
	{
		if(a[i][c]=='.')
			continue;
		int t = a[i][c]-'1';
		cnt[t]++;
		if(cnt[t]>1)
			return false;
	}

	return true;
}

bool box_checker(vvc &a,int r,int c)
{
	vi cnt(size+1,0);

	for(int i=r;i<r+3;i++)
	{
		for(int j=c;j<c+3;j++)
		{
			if(a[i][j]=='.')
				continue;
			int t = a[i][j]-'1';
			cnt[t]++;
			if(cnt[t]>1)
				return false;
		}
	}

	return true;
}

bool solve(vvc &a)
{
	vi ind = {0,3,6};

	//checking row
	rep(i,0,size-1)
	{
		if(!row_checker(a,i) || !column_checker(a,i))
			return false;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(!box_checker(a,ind[i],ind[j]))
				return false;
		}
	}

	return true;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: board = 
{{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}}
Output: true*/

    vvc a = {
    	{'5','3','.','.','7','.','.','.','.'},
    	{'6','.','.','1','9','5','.','.','.'},
    	{'.','9','8','.','.','.','.','6','.'},
    	{'8','.','.','.','6','.','.','.','3'},
    	{'4','.','.','8','.','3','.','.','1'},
    	{'7','.','.','.','2','.','.','.','6'},
    	{'.','6','.','.','.','.','2','8','.'},
    	{'.','.','.','4','1','9','.','.','5'},
    	{'.','.','.','.','8','.','.','7','9'}};

    cout<<solve(a)<<endl;


	return 0;
}

