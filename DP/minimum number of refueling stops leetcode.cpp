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

string getHash(int curr,int curr_fuel)
{
	return to_string(curr)+" "+to_string(curr_fuel);
}

unordered_map<string,int> um;
int recur(vvi &a,int curr,ll curr_fuel,int target)
{
	/*when all stations are behind*/
	if(curr==a.size())
	{
		int prev = curr==0?0:a[curr-1][0];
		if(prev + curr_fuel >=target)
			return 0;
		return 100000;	
	}

	string h = getHash(curr,curr_fuel);
	if(um.find(h)!=um.end())
		return um[h];

	/*if with the help of current fuel we can surpass the curr station
	  then we can chose to fill the fuel or not*/
	int prev = curr==0?0:a[curr-1][0];
	if(a[curr][0] - prev <=curr_fuel)
	{
		curr_fuel -= a[curr][0] - prev;
		return um[h] =  min
		(
			1+recur(a,curr+1,curr_fuel+a[curr][1],target),
			recur(a,curr+1,curr_fuel,target)
		);
	}

	/*if it cannot reach current station .... then it cannot reach the target anway*/
	return um[h] = 100000;
}

int solve(vvi &a,int curr_fuel,int target)
{
	um.clear();
	if(a.size()==0)
	{
		if(curr_fuel >= target)
			return 0;
		return -1;
	}

	/*when there exist atleast one station
	  and it cannot reach even first stations*/
	if(curr_fuel < a[0][0])
		return -1;

	int m = recur(a,0,curr_fuel,target);
	return m>=100000?-1:m;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2*/
/*100
50
[[50,50]]*/


    int target = 100;
    int startFuel = 50;
    vvi stations = {
    	{50,50}
    };

    cout<<solve(stations,startFuel,target)<<endl;

	return 0;
}
