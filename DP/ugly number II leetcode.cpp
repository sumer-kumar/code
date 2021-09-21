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

//leetcode solution
int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }

int solve(int n)
{
	vector<int> a;

	// a[0]=1;
	a.pb(1);

	int i5,i2,i3;
	i2=i3=i5=0;

	while(a.size()<n)
	{
		// cout<<a.back()<<" "<<i2<<" "<<i3<<" "<<i5<<endl;
		// for(int x : a)
		// 	cout<<x<<' ';
		// cout<<endl;

		// cout<<(2*a[i2])<<" "<<(3*a[i3])<<" "<<(5*a[i5])<<endl;
		// cout<<endl;

		if(2*a[i2] <= 3*a[i3] && 2*a[i2]<=5*a[i5])
		{
			// a[i] = 2*a[i2];
			if(a.back()!=2*a[i2])
			a.pb(2*a[i2]);
			i2++;
		}
		else if(3*a[i3] <= 2*a[i2] && 3*a[i3]<=5*a[i5])
		{
			// a[i] = 3*a[i3];
			if(a.back()!=3*a[i3])
			a.pb(3*a[i3]);
			i3++;
		}
		else 
		{
			// a[i] = 5*a[i5];
			if(a.back()!=5*a[i5])
			a.pb(5*a[i5]);
			i5++;
		}
	}


	return a[n-1];

}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=10;

    cout<<solve(n)<<endl;

	return 0;
}

