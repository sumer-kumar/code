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

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
           result = result/i;
           result = result*(i-1);
        }
    }
    if (n > 1)
           result = result/n,
           result = result*(n-1);
    return result;
}

void phiRangeN(int n)
{
	int ph[n+1];
	for(int i=0;i<=n;i++)
	{
		ph[i]=i;
	}

	for(int i=2;i<=n;i++)
	{
		if(ph[i]==i){
				for(int j=i;j<=n;j+=i)
				{
		
					ph[j]/=i;
					ph[j]*=(i-1);
				}}
	}

	for(int i=0;i<=n;i++)
	{
		cout<<i<<" --> "<<ph[i]<<endl;
	}
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int x;
    cin>>x;
    phiRangeN(x);

	return 0;
}