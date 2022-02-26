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


int solve(vi &a)
{
	int size = a.size();
	sort(a.begin(),a.end());

	vector<bool> vis(size,false);
	
	vi rem;

	for(int i=0;i<size;i++)
	{
		if(a[i]<=size && vis[a[i]]==false)
			vis[a[i]]=true;
		else
		rem.pb(a[i]);
	}

	int count = 0;

	sort(rem.begin(),rem.end());

	for(int x : rem)
		cout<<x<<" ";
	cout<<endl;

	int curr=0;

	for(int i=0;i<size;i++)
	{
		if(vis[i]==true)
			continue;
		count++;

		if(rem[curr++]-(i+1)<=(i+1))
			return -1;
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

		vi a(n);

		ininvi(a);
		cout<<solve(a)<<endl;

		cout<<a.size()<<endl;
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

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t>0){
        t--;
        int n;
        cin >> n;
        set<int> st;
        for(int i=1;i<=n;i++){st.insert(i);}
        vector<int> rem;
        for(int i=0;i<n;i++){
            int v;
            cin >> v;
            if(st.find(v)!=st.end()){st.erase(v);}
            else{rem.push_back(v);}
        }
        sort(rem.begin(),rem.end());
        reverse(rem.begin(),rem.end());
        int pt=0;
        bool err=false;
        for(auto &nx : rem){
            auto it=st.end();
            it--;
            int ctg=(*it);
            if(ctg>(nx-1)/2){err=true;break;}
            st.erase(it);
        }
        if(err){cout << "-1\n";}
        else{cout << rem.size() << '\n';}
    }
    return 0;
}
*/

// int recur(vi &a,int curr,vector<bool> &vis)
// {
// 	int size = a.size();
// 	if(curr>=size)
// 		return 0;

// 	if((a[curr]==curr+1) && (vis[curr]==false))
// 	{
// 		vis[curr]=true;
// 		int res = recur(a,curr+1,vis);
// 		vis[curr]=false;
// 		return res;
// 	}

// 	int ind = lower_bound(a.begin(),a.end(),curr+1)-a.begin();

// 	int res = MAX;

// 	for(int i=ind;i<size;i++)
// 	{
// 		if(curr+1==a[i] && vis[i]==false)
// 		{
// 			vis[i]=true;
			
// 			res = min(res,recur(a,curr+1,vis));

// 			vis[i]=false;
// 		}
// 		else if(curr+1<a[i] && vis[i]==false && (a[i]-(curr+1)>(curr+1)))
// 		{
// 			vis[i]=true;
			
// 			res = min(res,1+recur(a,curr+1,vis));

// 			vis[i]=false;
// 		}
// 	}

// 	return res>=MAX?MAX:res;
// }

// bool precheck1(vi &a)
// {
// 	int size = a.size();
// 	for(int i=0;i<size;i++)
// 	{
// 		if(i+1!=a[i])
// 			return false;
// 	}
// 	return true;
// }

// int precheck2(vi &a)
// {
// 	int size = a.size();
		
// 	int count = 0;

// 	for(int i=0;i<size;i++)
// 	{
// 		if(a[i]==(i+1))
// 			continue;
// 		if(a[i]-(i+1)<=i+1)
// 			return MAX;
// 		count++;
// 	}

// 	return count;
// }


// int solve(vi &a)
// {
// 	sort(a.begin(),a.end());

// 	//do some prechecks to reduce complexity
// 	if(precheck1(a))
// 		return 0;

// 	int res = precheck2(a);
// 	if(res<MAX)
// 		return res;

// 	int size = a.size();
// 	vector<bool> vis(size,false);

// 	res = recur(a,0,vis);

// 	return res>=MAX?-1:res;
// }