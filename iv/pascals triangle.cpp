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

vector<int>s getRow(int k) {

    vector<vector<int>> a(k+1,vector<int>(k+1));
    vector<vector<int>> t(2,vector<int>(k+1));

    a[0][0]=1;
    t[0][0]=1;
    
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                t[i%2][j]=1;
                a[i][j]=1;
            }

            else
            {
                t[i%2][j]=t[i%2][j]+a[(i-1)%2][j];
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
    }

    vector<int> res;
    for(int i=0;i<=k;i++)
    res.push_back(t[k%2][i]);

    return res;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	return 0;
}

