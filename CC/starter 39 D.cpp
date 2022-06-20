#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define int long long
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef priority_queue<int> pq_d;
typedef priority_queue<int,vector<int>,greater<int>> pq_a;
void ininarr(int a[],int size);
void ininvi(vi &a,int size=0);
void inllarr(ll a[],ll n);
void inllvi(vll &a,ll size=0);


void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

int solve()
{
    int n, k;
    cin >> n >> k;
    k = n - k;
    vector<vector<int>> g(n);
    set<pair<int, int>> blockable;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        if (x)
            blockable.insert({min(u, v), max(u, v)});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> subtree_size(n);
    auto dfs1 = [&](int u, int par, const auto &dfs1) -> void
    {
        subtree_size[u] = 1;
        for (int v : g[u])
        {
            if (v != par)
            {
                dfs1(v, u, dfs1);
                subtree_size[u] += subtree_size[v];
            }
        }
    };
    dfs1(0, -1, dfs1);
    multiset<int, greater<int>> to_remove;

    auto dfs2 = [&](int u, int par, const auto &dfs2) -> void
    {
        for (int v : g[u])
        {
            if (v != par)
            {
                if (blockable.find({min(u, v), max(u, v)}) != blockable.end())
                    to_remove.insert(subtree_size[v]);
                else
                    dfs2(v, u, dfs2);
            }
        }
    };
    dfs2(0, -1, dfs2);
    int ans = 0;
    for (int x : to_remove)
    {
        if (k <= 0)
            break;
        k -= x;
        ans++;
    }
    if (k > 0)
        return -1;
    return ans;
}


/*main-------------------------------------------->*/
signed main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}







/******INPUT THINGS*********/
void ininarr(int a[],int size)
{
	rep(i,0,size-1)
	{
		cin>>a[i];
	}
}

void ininvi(vi &a,int size)
{
	if(!size)
		size = a.size();
	rep(i,0,size-1)
	cin>>a[i];
}

void inllarr(ll a[],ll n)
{
	for(ll i=0;i<n;i++)
		cin>>a[i];
}

void inllvi(vll &a,ll size)
{
	if(!size)
		size=a.size();
	for(ll i=0;i<size;i++)
		cin>>a[i];
}