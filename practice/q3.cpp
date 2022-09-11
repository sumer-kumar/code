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
#define MAX 100
#define lli long long 
bool v[MAX];
int len, sp[MAX]={0};

void sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (lli j = 2; (j*i) < MAX; j += 2){
				v[j*i] = true;
				sp[j*i]++;
			}
		}
	}
}

int solve(vi &arr, int N, int K)
{
	sieve();
	for(int i=1;i<MAX;i++)
	{
		if(sp[i]==i)
			sp[i]=1;
		// cout<<sp[i]<<endl;
	}
	

    deque<int> Qi(K);
    int res = INT_MAX;

    int i;
    for (i = 0; i < K; ++i) {
 
        while ((!Qi.empty()) && sp[arr[i]] >= sp[arr[Qi.back()]])
 
            Qi.pop_back();

        Qi.push_back(i);
    }
 
    for (; i < N; ++i) {
        res = min(res,arr[Qi.front()]);
         while ((!Qi.empty()) && Qi.front() <= i - K)
            Qi.pop_front();
        while ((!Qi.empty()) && sp[arr[i]] >= sp[arr[Qi.back()]])
            Qi.pop_back();
 
        Qi.push_back(i);
    }
    res = min(res,arr[Qi.front()]);

    return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vi a = {2,4,6,10,5};
    int n = 5;
    int k = 3;
    cout<<solve(a,n,k)<<endl;

	return 0;
}

