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

//merging 
void merge(vector<pii> &a,int start1,int end1,int start2,int end2,vi &cnt)
{
	int i=start1;
	int j=start2;

	vector<pii> res(end2-start1+1);
	int k=0;

	while(i<=end1 && j<=end2)
	{
		if(a[i].fi<=a[j].fi)
		{
			res[k++]=a[j++];
		}
		else
		{
			cnt[a[i].se]+=end2-j+1;
			res[k++]=a[i++];
		}
	}

	while(i<=end1)
		res[k++]=a[i++];

	while(j<=end2)
		res[k++]=a[j++];


	rep(i,start1,end2)
	a[i]=res[i-start1];
}

//start and end are including the ends = size-1
//implement the merge sort
void recur(vector<pii> &a,int start,int end,vi &cnt)
{
	if(start==end)
		return;
	int mid = (start+end)/2;

	//splitiing 
	recur(a,start,mid,cnt);
	recur(a,mid+1,end,cnt);

	//merging 
	merge(a,start,mid,mid+1,end,cnt);
}

void solve(vi &a)
{
	int size = a.size();

	vector<pii> arr(size);
	vi cnt(size,0);

	rep(i,0,size-1)
	arr[i] = mp(a[i],i);

	recur(arr,0,arr.size()-1,cnt);

	for(auto x : cnt)
		cout<<x<<' ';
	cout<<endl;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Input: nums = [5,2,6,1]
Output: [2,1,1,0]*/

    vi a = {5,2,6,1};
    solve(a);

	return 0;
}

