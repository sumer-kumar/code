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

i am trying to divide the array into 3 parts
first calculate the maximum of window size k from each index from left to right
same from right to left of each index

then traverse the array try to fix the middle part 
_ _ _ _ (_ _) _ _ _ 
	  ^		  ^
	  |		  |
check from these index to left and to right
*/

void print(vi &a)
{
	for(int x : a)
		cout<<x<<" ";
	cout<<"\n";
}

void solve(vi &a,int k)
{
	int size = a.size();
	vi sum(size+1,0);

	rep(i,0,k-1)
	sum[0]+=a[i];

	rep(i,1,size-k)
	{
		sum[i] = sum[i-1] - a[i-1] + a[i+k-1];
	}

	vi left(size+1,0);
	left[0] = 0;

	rep(i,1,size-k)
	{
		if(sum[left[i-1]]<sum[i])
		{
			left[i]=i;
		}
		else
		{
			left[i]=left[i-1];
		}
	}

	vi right(size+1,0);

	right[size-k] = size-k;

	for(int i=size-k-1;i>=0;i--)
	{
		if(sum[right[i+1]]<sum[i])
		{
			right[i] = i;
		}
		else
		{
			right[i] = right[i+1];
		}
	}

	print(left);
	print(a);
	print(right);
	
	vi res = {left[0],k,right[k+k]};

	int res_sum = sum[res[0]] + sum[res[1]] + sum[res[2]];

	rep(i,k+1,size-k-k)
	{
		int curr_sum = sum[left[i-k]] + sum[i] + sum[right[i+k]];
		if(curr_sum>res_sum)
		{
			cout<<res_sum<<" "<<curr_sum<<endl;
			res_sum = curr_sum;
			res[0] = left[i-k];
			res[1] = i;
			res[2] = right[i+k];
		}
	}

	cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	//  0 1 2 3 4 5 6 7
    vi a = {1,2,1,2,1,2,1,2,1};
    int k=2;
    solve(a,k);

	return 0;
}
