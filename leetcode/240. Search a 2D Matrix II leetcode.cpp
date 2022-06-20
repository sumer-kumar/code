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

bool searchMatrix(vector<vector<int>>& a, int k) {
    
    int r = a.size();
    int c = a[0].size();
    
    int i=0;
    int j=c-1;
    
    while(i>=0 && i<r && j>=0 && j<c)
    {
        if(a[i][j]==k)
            return true;
        if(a[i][j]>k)
            j--;
        else
            i++;
    }
    return false;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /**/

	return 0;
}

