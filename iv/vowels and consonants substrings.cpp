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

#define mod 1000000007
int Solution::solve(string A) {
 int n=A.length();
    if(n==0 or n==1)
    return 0;
    int count=0;
    vector<int> vowel(n,0);
    vector<int> cons(n,0);
    for(int i=n-2;i>=0;i--)
    {
        if(A[i+1]=='a' or A[i+1]=='e' or A[i+1]=='i' or A[i+1]=='o' or A[i+1]=='u')
        {
            vowel[i]+=1;
        }
        else 
        {
            cons[i]+=1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        vowel[i]+=vowel[i+1];
        cons[i]+=cons[i+1];
    }
  
    for(int i=0;i<n-1;i++)
    {
        if(A[i]=='a' or A[i]=='e' or A[i]=='i' or A[i]=='o' or A[i]=='u')
        {
            count+=cons[i];
        }
        else
        count+=vowel[i];
    }
    return count%mod;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);




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