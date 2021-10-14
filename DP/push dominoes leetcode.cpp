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

#define INF 100001

string solve(string a)
{
	int size = a.size();
	vi r(size,INF);
	vi l(size,INF);

	//for right
	int i=0;
	while(i<size)
	{
		if(a[i]=='L' || a[i]=='.')
		{
			i++;
			continue;
		}

		i++;
		int t=1;
		while(i<size && a[i]=='.')
		{
			r[i]=t;
			i++;
			t++;
		}
	}

	//for left
	i=size-1;
	while(i>=0)
	{
		if(a[i]=='R' || a[i]=='.')
		{
			i--;
			continue;
		}
		i--;
		int t = 1;
		while(i>=0 && a[i]=='.')
		{
			l[i]=t;
			i--;
			t++;
		}
	}

	rep(i,0,size-1)
	{
		if(a[i]=='.')
		{
			if(r[i]<l[i])
				a[i]='R';
			else if(l[i]<r[i])
				a[i]='L';
		}
	}

	return a;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = ".L.R...LR..L..";

    cout<<solve(a)<<endl;

	return 0;
}

