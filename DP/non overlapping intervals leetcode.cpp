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
//not working giving tle
// bool cmp(vi &a,vi &b)
// {
// 	return a[0]<b[0];
// }

// string getHash(int a,int b)
// {
// 	return to_string(a)+" "+to_string(b);
// }

// unordered_map<string,int> um;
// int recur(vvi &a,int curr,int last)
// {
// 	if(curr>=a.size())
// 	{
// 		return 0;
// 	}

// 	if(um.find(getHash(curr,last))!=um.end())
// 		return um[getHash(curr,last)];

// 	/*for initial case*/
// 	if(last==-1)
// 	{
// 			two conditions are
// 			--> take curr element 
// 			-->	not take current element
		
// 		return um[getHash(curr,last)] = max(1+recur(a,curr+1,curr),recur(a,curr+1,last));
// 	}

// 	/*overlapping*/
// 	if(a[last][1]>a[curr][0]) 
// 	{
// 		return um[getHash(curr,last)] = max(recur(a,curr+1,last),recur(a,curr+1,curr));
// 	}
// 	/*not overlapping*/
// 	return um[getHash(curr,last)] = 1 + recur(a,curr+1,curr);
// }


// int solve(vvi &a)
// {

// 	sort(a.begin(),a.end(),cmp);

// 	return a.size()-recur(a,0,-1);
// }


bool cmp(vi &a,vi &b)
{
	return a[1]<b[1];
}

int solve(vvi &a)
{
	sort(a.begin(),a.end(),cmp);

	int count = 1;
	int curr = 0;

	int size = a.size();

	// for(auto x : a)
	// {
	// 	cout<<x[0]<<"<->"<<x[1]<<endl;
	// }

	rep(i,1,size-1)
	{
		/*consectutives are not overlapping*/
		if(a[i][0]>=a[curr][1])
		{
			count++;
			curr = i;
		}
	}

	return size - count;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*[[1,2],[2,3],[3,4],[1,3]]*/
    
    vvi a = {
    	{1,2},
    	{2,3},
    	{3,4},
    	{1,3}
    };

    cout<<solve(a)<<endl;

	return 0;
}

