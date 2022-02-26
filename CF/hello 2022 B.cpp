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

int solve(vvi &a)
{
	int minL,costL,maxR,costR,maxLen,costLen;
	int size = a.size();

	minL=a[0][0],costL=a[0][2];
	maxR=a[0][1],costR=a[0][2];
	maxLen=a[0][1]-a[0][0]+1;
	costLen = a[0][2];

	cout<<a[0][2]<<endl;

	for(int i=1;i<size;i++)
	{
		if(minL>a[i][0])
			minL=a[i][0],costL=a[i][2];
		if(minL==a[i][0])
			costL = min(costL,a[i][2]);

		if(maxR<a[i][1])
			maxR=a[i][1],costR=a[i][2];
		if(maxR==a[i][1])
			costR = min(costR,a[i][2]);

		if(maxLen < a[i][1]-a[i][0]+1)
			maxLen = a[i][1]-a[i][0]+1,costLen = a[i][2];
		if(maxLen == a[i][1]-a[i][0]+1)
			costLen = min(costLen,a[i][2]);

		int res = costL + costR;
		if(maxLen == maxR-minL+1)
			res = min(res,costLen);
		// cout<<"-----------------------"<<endl;
		// cout<<minL<<" "<<costL<<endl;
		// cout<<maxR<<" "<<costR<<endl;
		// cout<<maxLen<<" "<<costLen<<endl;


		cout<<res<<endl;
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

		vvi a(n,vi(3));

		rep(i,0,n-1)
		ininvi(a[i]);

		solve(a);
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
// string getHash(int a,int b)
// {
// 	return to_string(a)+" "+to_string(b);
// }
// void solve(vvi &a)
// {
// 	int size = a.size();

// 	int min_i = 0;
// 	int max_i = 0;

// 	//initial will be same
// 	cout<<a[0][2]<<endl;

// 	unordered_map<string,int> um;

// 	rep(i,1,size-1)
// 	{
// 		if(a[min_i][0]>a[i][0])
// 			min_i = i;
// 		else if(a[min_i][0]==a[i][0] && a[min_i][2]>a[i][2])
// 			min_i = i;

// 		if(a[max_i][1]<a[i][1])
// 			max_i = i;
// 		else if(a[max_i][1]==a[i][1] && a[max_i][2]>a[i][2])
// 			max_i = i;

// 		int sum = ((min_i == max_i)?a[min_i][2]:a[min_i][2]+a[max_i][2]);

// 		int low = a[min_i][0];
// 		int high = a[max_i][0];

// 		string hash = getHash(low,high);

// 		if(um.find(hash)!=um.end())
// 		{
// 			sum = um[hash];
// 		}
// 		else
// 		{
// 			for(int j=i;j>=0;j--)
// 			{
// 				if(a[j][0]==a[min_i][0] && a[j][1]==a[max_i][1])
// 				{
// 					sum = min(sum,a[j][2]);
// 				}
// 			}
// 			um[hash] = sum;
// 		}

// 		cout<<sum<<endl;
// 	}

// }
