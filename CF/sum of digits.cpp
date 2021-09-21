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

bool isValid(int m,int s)
{
	return (s >=0 && s <= m*9);
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,s;
    cin>>m>>s;

    string maxi="";

    if(s==0)
    {
    	cout<<(m==1?"0 0" : "-1 -1")<<endl;
    	return 0;
    }

    rep(i,1,m)
    {
    	for(int d = 9 ;d>=0;d--)
    	{
    		if(isValid(m-i,s-d))
    		{
    			maxi += '0' + d;
    			s-=d;
    			break;
    		}
    	}
    }

    string mini = maxi;
    reverse(mini.begin(),mini.end());

    if(mini[0]=='0')
    {
    	mini[0]='1';
    	rep(i,1,m-1)
    	{
    		if(mini[i]>'0')
    		{
    			mini[i] = char(mini[i]-1);
    			int p = 1;
    			break;
    		}
    	}
    }

    cout<<mini<<" "<<maxi<<endl;

	return 0;
}

