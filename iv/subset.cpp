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

void recur(vector<int> &a,int curr_index,vector<vector<int>>& res,vector<int> temp)
{
    //end of the array
    if(curr_index == a.size())
    {
        if(temp.size()==0)
        temp.push_back(INT_MIN);

        res.push_back(temp);

        return temp;
    }


    //dont include 
    recur(a,curr_index+1,res,temp);

    //include
    temp.push_back(a[curr_index]);
    recur(a,curr_index+1,res,temp);

}

void subsets(vector<int> &a) 
{
    vector<vector<int>> res;
    vector<int> temp;

    recur(a,0,res,temp);

    for(auto x : res)
    {
    	for(int p : x)
    	cout<<p<<" ";

    	cout<<endl;
    }

}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {1,2,3};

    subsets(a);

	return 0;
}

