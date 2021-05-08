#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isValid(int a[],int size,int roti,int mid);
bool isValid(int a[],int size,int roti,int mid);
int solve(int a[],int size,int roti);
// void defile()
// {
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif 
// }

int main() {
    // defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		
    int test;
    cin>>test;
    while(test--)
    {
    	int roti;
    	int chef;
    	cin>>roti;
    	cin>>chef;
    	int a[chef];
    	for(int i=0;i<chef;i++)
    	{
    		cin>>a[i];
    	}

    	cout<<solve(a,chef,roti)<<endl;
    }
	// cout<<"Nothing";

    // int a[] = {1,2,3,4};
    // int size = 4;
    // int roti = 10;
    // cout<<solve(a,size,roti);

	return 0;
}

int solve(int a[],int size,int roti)
{
	int start = 0;
	int end = 1e9;

	while(start<end)
	{
		int mid = start + (end - start)/2;
		if(isValid(a,size,roti,mid))
		{
			end = mid; 
		}
		else
		{
			start = mid + 1;
		}
	}
	return start;
}

bool isValid(int a[],int size,int roti,int mid)
{
	int count = 0;
	int time = 0;
	for(int i=0;i<size;i++)
	{
		time=a[i];
        // count++;
		int multiplier = 2;
		while(time<=mid)
		{	time = time + a[i]*multiplier;
			count++;
			multiplier++;
            if(count>=roti)
                return true;
		}

	}
	return false;
}

















