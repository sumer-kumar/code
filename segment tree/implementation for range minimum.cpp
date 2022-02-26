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

/**
 * SEGMENT TREE OF MINIMUM VALUE OVER A RANGE
 * 
 * */

/*recursive call for creating segment tree*/
void create(vi &a,vi &st,int start,int end,int st_index)
{
	/*checking for the leaf node*/
	if(start==end)
	{
		st[st_index] = a[start]; /*or a[end]*/
		return;
	}

	int mid = (start+end)/2;

	int left_index = 2*st_index;
	int right_index = 2*st_index+1;

	/*do for left*/
	create(a,st,start,mid,left_index);

	/*do for right*/
	create(a,st,mid+1,end,right_index);

	/*choose the minimum of both left and right subtree of the current node*/
	st[st_index] = min(st[left_index],st[right_index]);
}

int query(vi &st,int st_index,int start,int end,int q_start,int q_end) /*q for query*/
{
	/*out of range of the given query*/
	if( end<q_start || start>q_end )
		return INT_MAX;

	/*completly inside of the query*/
	if(start>=q_start && end<=q_end)
		return st[st_index];

	int mid = (start+end)/2;
	int left_index = 2*st_index;
	int right_index = 2*st_index+1;	

	int left_res = query(st,left_index,start,mid,q_start,q_end);
	int right_res = query(st,right_index,mid+1,end,q_start,q_end);

	return min(left_res,right_res);
}

void buildSetgemtTree(vi &a)
{
	int size = a.size();
	int range = size*2+1;

	vi st(range+2);
	create(a,st,0,size-1,1);

	rep(i,0,range+1)
	cout<<st[i]<<" ";
	cout<<endl;

	cout<<query(st,1,0,size-1,1,5)<<endl;
}

//to update segment tree with upi = update index, upv = update value
void update(vi &st,int si,int ss,int se,int upi,int upv)
{
	if(ss==se)
	{
		st[ss] = upv;
		return;
	}

	int mid = (ss+se)/2;

	if(upi<mid)
		update(st,si*2,ss,mid,upi,upv)
	else
		update(st,si*2+1,mid+1,se,upi,upv);

	st[si] = min(st[si*2],st[si*2+1]);
}



/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// 			0  1  2  3  4  5
    vi a = {1, 3, 2, 7, 9, 11};

    buildSetgemtTree(a);

	return 0;
}
