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

/*
	state : 0 : last is zero
	state : 1 : last is one
*/
// gives tle and no way to memoize
// int recur(int n,int lg,int curr,int state)
// {

// 	if(curr>n)
// 		return 0;

// 	if(lg==0)
// 	{
// 		return 1;
// 	}

// 	if(state==0)
// 	{
// 		return recur(n,lg-1,(curr<<1)|1,1) + recur(n,lg-1,curr<<1,0);
// 	}
// 	/*state 1 */
// 	else
// 	{
// 		return recur(n,lg-1,curr<<1,0);
// 	}
// }

// int solve(int n)
// {
// 	int lg = log2(n)+1;
// 	return recur(n,lg,0,0);
// }



int solve(int n)
{
	/*if we carefully observe the output pattern for first few bits irrespective of value of 'n'
	we can see it is just like fibonacci series
	f[n] = f[n-1]+f[n-2];
	so first calculate the fibonacci values for first 32 bits
	*/
	int N=32;
	vi fib(33,0);
	fib[0]=1;
	fib[1]=2;
	fib[2]=3;
	rep(i,3,32)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}

	/*after that calculate valid numbers
	example 1001 0110
	so we have to calculate valid numbers just less than 
	1000 0000 => range [0,0111 1111]
    0001 0000 => range [0,0000 1111]
	0000 0100 => range [0,0000 0011]
	0000 0010 => range [0,0000 0001]
	but we have to stop after
	0000 0100 because there is consecutive 0's there
	*/

	int i=30;
	int sum = 0;
	bool prev_set_bit = false;

	while(i>=0)
	{
		if(n & (1<<i))
		{
			sum += fib[i];
			if(prev_set_bit==true)
				return sum;
			prev_set_bit=true;
		}
		else
		prev_set_bit=false;
		i--;
	}

	return sum+1; /*one for current element*/
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=11;

    cout<<solve(n)<<endl;

	return 0;
}

