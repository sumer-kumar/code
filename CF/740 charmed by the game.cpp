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


void solve(int A,int B)
{

	//number of serves for first 
	int u=(A+B)/2;
	int v=(A+B)-u;

	set<int> st;

	//number of wins in serving for first player
	int ab,a,bb,b;

	rep(i,0,u)
	{
		ab=i;
		a=A-i;

		b=u-ab;
		bb=B-b;

		if(ab>=0 &&a>=0 && bb>=0 && b>=0)
		{
			st.insert(ab+bb);
		}
	}

	rep(i,0,v)
	{
		ab=i;
		a=A-i;
		b=v-ab;
		bb=B-b;

		if(ab>=0 &&a>=0 && bb>=0 && b>=0)
		{
			st.insert(ab+bb);
		}
	}

	cout<<st.size()<<endl;

	for(int x : st)
		cout<<x<<" ";
	cout<<endl;
}

// void solve(int a,int b)
// {

// 		set<int> ways;
//         // 0 1 0 1 0 1...
//         // case 1
//         int oddPos,evenPos;
//         oddPos = (a+b)/2;
//         evenPos = ( a+ b - oddPos);

//         // ways for alice to cause problem, alice is 0
//         rep(i,0,oddPos){
//             // alice wins in these many odd position
//             int ao,ae,bo,be;
//             ao = i;
//             ae = a - i;
//             bo = oddPos - ao;
//             be = evenPos - ae;

//             if((ae) < 0 || bo < 0 || be < 0) continue;

//             ways.insert( ( ao + be));
//         }


//         // ways for alice to cause problem, alice is 1
//         rep(i,0,evenPos){
//             // alice wins in these many even position
//             int ao,ae,bo,be;
//             ae = i;
//             ao = a - i;
//             bo = oddPos - ao;
//             be = evenPos - ae;

//             if(ao < 0 || (ae) < 0 || bo < 0 || be < 0) continue;

//             ways.insert( ( ae + bo));
//         }
//         cout << ways.size() << endl;
//         for(auto node : ways) cout << node << " ";
//         cout << endl;
// }


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
		int a,b;
		cin>>a>>b;

		solve(a,b);    	
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