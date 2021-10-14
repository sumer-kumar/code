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

int solve(int n, int d){
    int nn = n;
    int rem; 
    int count =0;
    int c = 0;
    while(nn>0){
        rem = nn % 10;
        nn = nn /10;
        c++;
        if(rem == d){
            nn = nn*pow(10,c)+(rem+1)*pow(10,c-1);
            count = nn -n;
            c = 0;
        }
    }
    return count;
}

/*main-------------------------------------------->*/
int main() {
    defile();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        cout<<solve(n, d)<<endl;
    }
    return 0;
}

