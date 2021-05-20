#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i=a; i<=b; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

// void defile()
// {
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif 
// }

ll getCost(priority_queue<pair<int,bool>> &pq)
 {
 	ll cost = 0;
 	int rcut=1;
 	int ccut=1;
 	while(!pq.empty())
 	{

 		// cout<<cost<<" "<<pq.top().fi<<" "<<pq.top().se<<endl;
 		// cout<<"rcut : "<<rcut<<endl;
 		// cout<<"ccut : "<<ccut<<"\n\n";

 		if(pq.top().se == true)/*row condition*/
 		{
 			cost += ccut*(pq.top().fi);
 			rcut++;
 		}
 		else /*column condition*/
 		{
 			cost += rcut*(pq.top().fi);
 			ccut++;
 		}

 		pq.pop();
 	}
 	return cost;
 }


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;	

	int row,col;
	int d;

	while(t--)
	{
		priority_queue<pair<int,bool>> pq;/*true for row false for column*/
		cin>>row>>col;

		/*push row*/
		rep(i,0,row-2)
		{
			cin>>d;
			pq.push({d,true});
		}

		/*push column*/
		rep(i,0,col-2)
		{
			cin>>d;
			pq.push({d,false});
		}

		cout<<getCost(pq)<<endl;

	}

	return 0;
}