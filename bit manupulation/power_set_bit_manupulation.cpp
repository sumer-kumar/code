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

vector<string> powerset(string a)
{
	vector<string> ps ;
	string temp;
	int size = a.size();

	for(int i=1;i<(1<<size);i++)
	{
		string temp = "";
		for(int j=0;j<size;j++)
		{
			if(i&(1<<j))
			{	
				temp+=a[j];
			}
		}
		ps.push_back(temp);
	}
	return ps;
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string a;
	cin>>a;

	vector<string> ps = powerset(a);
	for(string x : ps)
	{
		cout<<x<<endl;
	}	

	return 0;
}