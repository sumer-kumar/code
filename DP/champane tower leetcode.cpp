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


double solve(int poured,int r,int c)
{
	double result[101][101] = {0.0};
        result[0][0] = poured;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[r][c];
}

/*
0
0 0
0 0 0
0 0 0 0
0 0 0 0 0
*/

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*poured = 2, query_row = 1, query_glass = 1*/
    int poured=100000009;
    int r = 33;
    int c = 17;

    cout<<solve(poured,r,c)<<endl;

	return 0;
}

