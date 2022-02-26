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

int left(int curr)
{
	if(curr-1<0)
		return 3;
	return curr-1;
}

int right(int curr)
{
	if(curr+1>3)
		return 0;
	return curr+1;
}

bool isNegative(int a){return a<0;}
bool isPositive(int a){return a>0;}

bool solve(string &a)
{
	/*
	face = 0 : North
	face = 1 : East
	face = 2 : South
	face = 3 : North
	*/

	int face=0;

	int i=0;
	int j=0;

	for(char x : a)
	{
		if(x=='G')
		{
			switch(face)
			{
				case 0: i++;
						break;
				case 1: j++;
						break;
				case 2: i--;
						break;
				case 3: j--;
						break;
			}
		}
		else if(x=='L')
		{
			face = left(face);
		}
		else /*x=='R*/
		{
			face = right(face);
		}
	}

	return i==0 && j==0 || face>0;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "GLLLL";

    cout<<solve(a)<<endl;

	return 0;
}