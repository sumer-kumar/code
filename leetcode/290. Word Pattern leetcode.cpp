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

vector<string> extract(string a)
{
	vector<string> res;
	a.pb(' ');
	int start=0;
	int size = a.size();
	for(int i=1;i<size;i++)
	{
		if(a[i]==' ')
		{
			res.pb(a.substr(start,i-start));
			start=i+1;
		}
	}

	return res;
}

bool solve(string &a,string &b)
{
	//turn b into vector of words
	vector<string> bb=extract(b);

	int size = a.size();
	if(bb.size()!=size)
		return false;

	unordered_map<char,int> um;
	unordered_map<string,char> um2; //string to char mapping

	for(int i=0;i<size;i++)
	{
		//if not found
		if(um.count(a[i])==0)
		{
			if(um2.count(bb[i])==0){
				um[a[i]]=i;
				um2[bb[i]]=a[i];
			}
			else
			{
				return false;
			}
		}
		else
		{
			if(bb[um[a[i]]]!=bb[i])
				return false;
		}
	}

	return true;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*pattern = "abba", s = "dog cat cat dog"*/
    string a = "abba";
    string b = "dog cat cat dog";

/*"abba"
"dog dog dog dog"*/
	// string a = "abba";
	// string b = "dog dog dog dog";    

    cout<<solve(a,b)<<endl;

	return 0;
}

