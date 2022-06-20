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


void solve(vi &a,vi &b,int size)
{
	vvi res;

	rep(i,0,size-1)
	{
		rep(j,i+1,size-1)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
				swap(b[i],b[j]);
				res.pb({i,j});
			}
		}
	}

	rep(i,0,size-1)
	{
		int k=i;
		while(k<size && a[k]==a[i])
			k++;
		
		k--;

		// cout<<i<<" "<<k<<endl;

		rep(j,i,k)
		{
			rep(l,j+1,k)
			{
				if(b[i]>b[l])
				{
					swap(b[i],b[l]);
					res.pb({i,l});
				}
			}
		}
	}

	if(!is_sorted(b.begin(),b.end()))
	{
		cout<<"-1"<<endl;
		return;
	}

	cout<<res.size()<<endl;
	for(auto x : res)
	{
		cout<<x[0]+1<<" "<<x[1]+1<<endl;
	}	

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

 		vi a(n);
 		vi b(n);
 		ininvi(a);
 		ininvi(b);

 		solve(a,b,n);
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

/*bool cmp(vi &a,vi &b)
{
	if(a[0]<=b[0] && a[1]<=b[1])
		return true;

	return false;
}

bool isSorted(vvi &t)
{
	int size = t.size();
	rep(i,1,size-1)
	{
		if(t[i][0]<t[i-1][0] || t[i][1]<t[i-1][1])
			return false;
	}
	return true;
}

void solve(vi &a,vi &b,int size)
{
	map<pair<int,int>,unordered_set<int>> mp;

	rep(i,0,size-1)
	{
		mp[{a[i],b[i]}].insert(i);
	}

	vvi t(size,vi(2));

	rep(i,0,size-1)
	{
		t[i][0]=a[i];
		t[i][1]=b[i];
	}

	sort(t.begin(),t.end(),cmp);

	// for(auto x : t)
	// {
	// 	for(int p : x)
	// 		cout<<p<<" ";
	// 	cout<<endl;
	// }
	// cout<<"\n\n";

	if(!isSorted(t))
	{
		cout<<"-1"<<endl;
		return;
	}

	int cnt=0;
	vvi sw;

	rep(i,0,size-1)
	{
		//need of swap
		if(a[i]!=t[i][0] || b[i]!=t[i][1])
		{
			cnt++;

			int ind = *(mp[{t[i][0],t[i][1]}].begin());

			if(ind<0)
				cout<<"efesefs"<<endl;

			//update in map
			mp[{t[i][0],t[i][1]}].erase(mp[{t[i][0],t[i][1]}].begin());

			mp[{a[i],b[i]}].erase( mp[{a[i],b[i]}].find(i) );

			mp[{a[i],b[i]}].insert(ind);

			swap(a[i],a[ind]);
			swap(b[i],b[ind]);

			sw.push_back({i,ind});
		}
		else
		{
			//remove from the map
			mp[{a[i],b[i]}].erase(mp[{a[i],b[i]}].find(i));
		}
	}

	cout<<cnt<<endl;
	for(auto x : sw)
	{
		cout<<x[1]+1<<" "<<x[0]+1<<endl;
	}


}
*/