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


int solve(vi &a,int n)
{
	int size = a.size();
	int cnt=0;
	int i=1;
	//checking for first element
	if(a[0]==0 && a[1]==0)
	{
		cnt++;
		i=2;
	}

	for( ;i<size;i++)
	{
		if(i==size-1)
		{
			if(a[i]==0 && a[i-1]==0)
				cnt++;
		}
		if(i<size-1 && a[i]==0 && a[i-1]==0 && a[i+1]==0)
		{
			a[i]=1;
			cnt++;
			i++;
		}		
	}
	return cnt>=n?1:0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: flowerbed = [1,0,0,0,1], n = 1
Output: true*/

    vi a = {1,0,0,1,0};
    int n=2;
    cout<<solve(a,n)<<endl;

	return 0;
}

