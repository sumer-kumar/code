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

int calImp(char a[],int n)
{
	int count = 0;
	rep(i,1,n-1)
	{
		if(a[i-1]==a[i])
			count++;
	}
	return count;
}

int solve(char a[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(a[i]=='?')
		{
			if(a[i-1]=='B')
				a[i]='R';
			else
				a[i]='B';
		}
	}
	return calImp(a,n);
}
/*
B R B R B B R
R B R B R B R
? ? ? ? ? B ?
*/
//main-------------------------------------------->
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
		char a[n+1];
		char cpy[n+1];
		char res[n+1];
		rep(i,0,n-1)
		cin>>a[i];
		a[n]='\0';

		if(a[0]=='?')
		{
			//case 1
			strcpy(cpy,a);
			a[0]='B';
			cpy[0] ='R';


			if(solve(a,n) < solve(cpy,n))
			{
				strcpy(res,a);
			}
			else
			{
				strcpy(res,cpy);
			}
		}
		else
		{
			strcpy(cpy,a);
			solve(cpy,n);
			strcpy(res,cpy);
		}
		printf("%s\n",res);
	}    


	return 0;
}

