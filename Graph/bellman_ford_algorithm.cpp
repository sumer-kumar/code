#include <bits/stdc++.h>
using namespace std;
#define ll long long

void defile()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}


int isNegativeCycle(vector<vector<int>> a,int V,int source);

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V,E;
    cin>>V>>E;

    vector<vector<int>> a;

    int from,to,w;
    from = to = 1;
    while(from>=0&&to>=0)
    {
    	cin>>from>>to>>w;
    	if(from>=0&&to>=0)
    	{
    		vector<int> t (3);
    		t[0] = from;
    		t[1] = to;
    		t[2] = w;
    		a.push_back(t);
    	}
    }

    cout<<isNegativeCycle(a,V,0);

	return 0;
}

int isNegativeCycle(vector<vector<int>> a,int V,int source)
{
	int INF = 1000000;

	vector<int> dist(V,INF);
	dist[source] = 0;

	for(int i=0;i<V;i++)
	{	
		for(auto x : a)
		{
			if(dist[x[0]]<INF)
			{
				if( dist[x[1]] > dist[x[0]]+x[2])
				{
					dist[x[1]] = dist[x[0]]+x[2];
				}
			}
		}
	}

	for(auto x : a)
	{
		if(dist[x[0]]<INF)
		{
			if( dist[x[1]] > dist[x[0]]+x[2])
			{
				return 1;
			}
		}
	}
	for(int i=0;i<V;i++)
		cout<<i<<" : "<<dist[i]<<endl;

	return 0;
}
