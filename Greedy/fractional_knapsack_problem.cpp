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

struct Item{
    int value;
    int weight;
};

typedef Item node;


bool cmp(node a,node b);
int fractional_knapsack(int n,int capacity,node a[]);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    node a[n];

    for(int i=0;i<n;i++)
    	cin>>a[i].value>>a[i].weight;

    int capacity;
    cin>>capacity;

    cout<<fractional_knapsack(n,capacity,a)<<endl;

	return 0;
}

bool cmp(node a,node b)
{
	return (((double)a.value/a.weight) > ((double)b.value/b.weight));
}

int fractional_knapsack(int n,int capacity,node a[])
{
	/*sort a wrt value*/
	sort(a,a+n,cmp);
	int remain = capacity;
	int prof = 0;

	for(int i=0;i<n;i++)
	{
		if( a[i].weight <= remain)
		{
			prof += a[i].value;
			remain -= a[i].weight;
		}
		else
		{
			prof += (a[i].value/a[i].weight)*remain;
			break;
		}
	}
	return prof;
}