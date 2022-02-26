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

int solve(string v1, string v2) {
    // support variables
    int i = 0, j = 0, v1Len = v1.size(), v2Len = v2.size(), n1, n2;
    while (i < v1Len || j < v2Len) {
        // computing the next set of version sub-values
        n1 = 0;
        n2 = 0;
        while (i < v1Len && v1[i] != '.') n1 = n1 * 10 + (v1[i++] - '0');
        while (j < v2Len && v2[j] != '.') n2 = n2 * 10 + (v2[j++] - '0');
        // handling possible results
        if (n1 < n2) return -1;
        else if (n1 > n2) return 1;
        i++;
        j++;
    }
    return 0;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "1.01";
    string b = "01.001";

    cout<<solve(a,b)<<endl;

	return 0;
}

