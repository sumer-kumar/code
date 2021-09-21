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


int dsu_find(vi &p,int x)
{
	// cout<<x<<endl;
	if(p[x]==x)
		return x;
	return p[x] = dsu_find(p,p[x]);
}

void dsu_union(vi &p,int a,int b)
{
	int p1 = dsu_find(p,a);
	int p2 = dsu_find(p,b);

	if(p1==p2)
		return;
	p[p2]=p1;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    //implement dsu
    vi p1(n+1);
    vi p2(n+1);

    //initialize parent array
    rep(i,0,n)
    {
    	p1[i]=i;
    	p2[i]=i;
    }
    int n1,n2;
    cin>>n1>>n2;

    vector<pair<int,int>> a1(n1);
    vector<pair<int,int>> a2(n2);


    rep(i,0,n1-1)
    {
    	int from,to;
    	cin>>from>>to;
    	a1[i]={from,to};
    	dsu_union(p1,from,to);
    }

    rep(i,0,n2-1)
    {
    	int from,to;
    	cin>>from>>to;
    	a2[i] = {from,to};
    	dsu_union(p2,from,to);
    }

    vector<pair<int,int>> res;
    for(int i=1;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)	
    	{
    		if( dsu_find(p1,i)!=dsu_find(p1,j) &&
    		 	dsu_find(p2,i)!=dsu_find(p2,j))
    		{
    			res.pb({i,j});
    			dsu_union(p1,i,j);
    			dsu_union(p2,i,j);
    		} 
    	}
    }
    cout<<res.size()<<endl;
    for(auto x : res)
    	cout<<x.first<<" "<<x.second<<endl;

	return 0;
}

