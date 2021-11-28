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


int solve(vi &a) 
{
    int size = a.size();

    if(size == 0 || size == 1)
    return 0;

    int left[size];
    int right[size];

    //for left max
    left[0]=a[0];
    for(int i=1;i<size;i++)
    {
        left[i] = max(left[i-1],a[i]); 
    }

    //for right max
    right[size-1]=a[size-1];
    for(int i=size-2;i>=0;i--)
    {
        right[i] = max(right[i+1],a[i]);
    }

    int trapped = 0;

    int min_height;

    for(int i=0;i<size;i++)
    {
        trapped += min(left[i],right[i])-a[i];
    }

    return trapped;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<solve(a)<<endl;

	return 0;
}

