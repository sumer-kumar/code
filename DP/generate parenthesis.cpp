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


void recur(int a,int b,int curr,string &op,vector<string> &res,int pos)
{
    if(a==0 && b==0)
    {
        res.pb(op);
    }

    if(curr>0)
    {
        if(b>0)
        {
            op[pos]=')';
            recur(a,b-1,curr-1,op,res,pos+1);
        }

        if(a>0)
        {
            op[pos]='(';
            recur(a-1,b,curr+1,op,res,pos+1);
        }
    }

    else if(a>0)
    {
        op[pos]='(';
        recur(a-1,b,curr+1,op,res,pos+1);
    }
}


void solve(int n)
{
    int a = n;
    int b = n;

    int curr = 0;

    string t="";
    rep(i,0,2*n-1)
    t.pb(' ');
    
    vector<string> res;
   
    recur(a,b,curr,t,res,0);

    for(string x : res)
        cout<<x<<endl;
    
    return res;
    
}


// void solve(int n)
// {

// }


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=3;

    solve(n);

	return 0;
}

