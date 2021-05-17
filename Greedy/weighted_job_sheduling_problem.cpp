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

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

typedef Job node;
bool cmp(node a,node b)
{
	return a.profit>b.profit;
}

void maxProfit(node a[],int size)
{
	/*sort accourding to the profit*/
	sort(a,a+size,cmp);

	int maxDeadline = 0;
	/*find maximum deadline*/
	for(int i=0;i<size;i++)
		maxDeadline = max(maxDeadline,a[i].dead);
	
	for(int i=0;i<size;i++)
		cout<<a[i].profit<<" "<<a[i].id<<endl;

	/*make array of maximum deadline*/
	vector<bool> arr(maxDeadline+1,false);
	int sum = 0;
	int cnt=0;
	for(int i=0;i<size;i++)
	{
		/*pick one*/
		if(arr[a[i].dead]==false)
		{
			sum += a[i].profit;
			arr[a[i].dead] = true;
			cnt++;
		}
		else
		{
			for(int j=a[i].dead-1;j>0;j--)
			{
				if(arr[j]==false)
				{
					arr[j] = true;
					sum+=a[i].profit;
					cnt++;
				}
			}
		}
	}

	cout<<"profit : "<<sum<<endl;
	cout<<"count : "<<cnt<<endl;

	for(bool x : arr)
		cout<<x<<" ";
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// (1,4,20)(2,1,10)(3,1,40)(4,1,30)
	Job arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    maxProfit(arr,n);

	return 0;
}