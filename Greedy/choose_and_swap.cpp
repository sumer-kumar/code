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

string solve(string a)
{
	set<char> s;
	for(int i=0;i<a.size();i++)
		s.insert(a[i]);

	unordered_set<char> us;
	vector<char> l;

	for(int i=0;i<=a.size();i++)
	{
		if(us.find(a[i])==us.end()) 
		{
			us.insert(a[i]);
			l.push_back(a[i]);
		}
	}
	unordered_map<char,char> um;
	int i=0;
	for(auto x = s.begin();x!=s.end();x++,i++)
	{
		// cout<<*x<<" "<<l[i]<<endl;
		if(*x != l[i])
		{
			um[l[i]] = *x;
			um[*x] = l[i];
			break;
		}
	}
	
	if(um.size()>0)
	{
		for(i=0;i<a.size();i++)
		{
			if(um.find(a[i])!=um.end())
				a[i] = um[a[i]];
		}
	}
	return a;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
   	cin>>a;
   	cout<<solve(a)<<endl;
	return 0;
}
