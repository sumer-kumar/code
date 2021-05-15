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
int snakes_and_ladder(int a[],int size);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int N = 30;
    int a[N];
    for (int i = 0; i<N; i++)
        a[i] = -1;
  
    // Ladders
    a[2] = 21;
    a[4] = 7;
    a[10] = 25;
    a[19] = 28;
  
    // Snakes
    a[26] = 0;
    a[20] = 8;
    a[16] = 3;
    a[18] = 6;


    cout<<snakes_and_ladder(a,N)<<endl;
	
	return 0;
}

int snakes_and_ladder(int a[],int size)
{
	queue<pair<int,int>> q; /*first->position second->moves*/	
	q.push({0,0});

	bool visited[size] = {false};
		
	while(!q.empty())
	{
		pair<int,int> x = q.front();
		q.pop();
		
		int curr = x.first;
		int dist = x.second;

		if(curr==size-1)
			return dist;

		for(int i=curr+1;i<=curr+6&&i<size;i++)
		{

			if(!visited[i])
			{
				if(a[i]==-1) /*normal cell*/
				{
					q.push({i,dist+1});
				}
				else /*snakes or ladder*/
				{
					q.push({a[i],dist+1});
					visited[a[i]] = true;
				}
				visited[i] = true;
			}
		}
	}
	return -1;
}