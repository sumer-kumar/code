#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}


int getTimes(int h,int a)
{
	int t = 1;
	int prev = 0;
	h += 3;
	a += 2;
	bool isAlive;

	while(h>0 && a>0)
	{
		isAlive = false;
		
		if(prev!=0)
		{
			h += 3;
			a += 2;
			prev = 0;
			isAlive = true;
		}
		else if( prev != 1 && h>5 && a>10)
		{
			h -= 5;
			a -= 10;
			prev = 1;
			isAlive = true;
		}
		else if(prev!=2 && h>20)
		{
			h -= 20;
			a += 5;
			prev = 2;
			isAlive = true;
		}
		if(!isAlive)
			break;

		t++;
	}
	return t;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;

	int h,a;

	while(t--)
	{
		cin>>h>>a;
		cout<<getTimes(h,a)<<endl;
	}	

	return 0;
}