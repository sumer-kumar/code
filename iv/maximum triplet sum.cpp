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
int solve(vector<int> &A) {
    //making a right max suffix
    //put traversed element in array
    int ans=0;
    int n=A.size();
    vector<int> right(n, 0);
    for(int i=n-2; i>=0; i--) {
        int mx = max(right[i+1], A[i+1]);
        if(mx>A[i]) right[i]=mx;
    }
    set<int> s;
    s.insert(A[0]);
    for(int i=1; i<n-1; i++) {
        s.insert(A[i]);
        if(right[i]!=0) {
            auto itr = s.find(A[i]);
            if(itr!=s.end()) {
                ans = max(ans, (A[i]+(*(--itr))+right[i]));
            }
        }
    }
    return ans;
}


/*main-------------------------------------------->*/
int main() {
    defile();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

