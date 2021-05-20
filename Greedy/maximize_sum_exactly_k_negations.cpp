#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef priority_queue<int> pq_d; /*max heap*/
typedef priority_queue<int,vector<int>, greater<int>> pq_a; /*min heap*/ 
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
ll maxSum(vi a,int k)
{
	/*make a min heap*/
	pq_a pq;

	for(int x : a)
		pq.push(x);

	while(k--)
	{
		int t = pq.top();
		pq.pop();

		pq.push(-t);
	}
	ll sum =0;
	while(!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	return sum;

}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	vi a(n);
	rep(i,0,n-1)
		cin>>a[i];
	int k;
	cin>>k;
	cout<<maxSum(a,k)<<endl;
	return 0;
}

// typedef long long int ll;
//     long long int maximizeSum(long long int a[], int n, int k)
//     {
//         sort(a,a+n);
//         ll sum=0, i;
//         for(i=0;i<n;i++){
//             if(a[i]<0 and k>0){
//                 a[i]*=-1;
//                 k--;
//             }
//         }
        
//         sort(a,a+n);
//         for(i=0;i<n;i++)
//         sum+=a[i];
        
//         if(k&1)
//         sum-=2*a[0];
        
//         return sum;