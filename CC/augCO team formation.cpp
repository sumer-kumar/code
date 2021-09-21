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


int solve(vc &p,vc &e,int size)
{
	int ee,pp,ep,oo;
	ee=pp=ep=oo=0;

	rep(i,0,size-1)
	{
		if(p[i]=='0' && e[i]=='0')
			oo++;
		else if(p[i]=='0' && e[i]=='1')
			ee++;
		else if(p[i]=='1' && e[i]=='0')
			pp++;
		else
			ep++;
	}

	int count = 0;

	while(true)
	{
		if(ee>0 && pp>0)
		{
			ee--;
			pp--;
			count++;
			continue;
		}
		else if(ep>0 && ee>0)
		{
			ep--;
			ee--;
			count++;
			continue;
		}
		else if(ep>0 && pp>0)
		{
			ep--;
			pp--;
			count++;
			continue;
		}
		else if(ep>0 && oo>0)
		{
			ep--;
			oo--;
			count++;
			continue;
		}
		else if(ep>=2)
		{
			ep-=2;
			count++;
			continue;
		}
		break;
	}

	return count;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;

    	vector<char> pp(n);
    	vector<char> ee(n);

    	rep(i,0,n-1)
    	cin>>pp[i];

    	rep(i,0,n-1)
    	cin>>ee[i];

    	cout<<solve(pp,ee,n)<<endl;

    }


	return 0;
}

