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
// 0 1 2 
// 3 4 9
// 3 9 18


int giveSum(vi &a,vi &sum,int k)
{

	auto x = upper_bound(a.begin(),a.end(),k);
	if(x==a.end())
		return sum.back();

	int ind = x-a.begin();

	return sum[ind]-a[ind] + k*(a.size()-ind);
}

int solve(vi &a,int t)
{
	int size = a.size();
	//sort first 
	sort(a.begin(),a.end());

	int start=0;
	int end=a[0];

	rep(i,0,size-1)
	{
		end=max(end,a[i]);
	}

	vi sum(size,0);
	sum[0]=a[0];

	rep(i,1,size-1){
		sum[i]+=a[i]+sum[i-1];
	}

	int min_diff=INT_MAX;
	int mid_val=-1;

	cout<<start<<" "<<end<<endl;

	while(start<=end)
	{
		int mid = start+(end-start)/2;

		int temp = giveSum(a,sum,mid);

		cout<<temp<<" "<<mid<<endl;

		if(temp>t){
			end=mid-1;
		}
		else{
			start=mid+1;
		}

		int diff = abs(temp-t);

		if(diff<min_diff || (diff==min_diff && mid_val>mid))
		{
			min_diff = diff;
			mid_val = mid;

		}else if(diff==0 && mid_val>mid){
			mid_val=mid;
		}
	}

	return mid_val;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	/*Input: arr = [4,9,3], target = 10
	Output: 3*/
	
    vi a = {2,3,5};
    int t = 10;

    cout<<solve(a,t)<<endl;
    

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