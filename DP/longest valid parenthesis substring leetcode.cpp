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

int solve(string &str)
{
	/*using stack*/
    int n = str.length();
 
    // Create a stack and push -1 as
    // initial index to it.
    stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
         
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            // Pop the previous opening
            // bracket's index
            if (!stk.empty())
            {
                stk.pop();
            }
             
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
 
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
 
    return result;
}


/*wrong method*/
int solve2(string &a)
{
	int size = a.size();
	vi s(size,0);
	s[0] = a[0]=='(' ? 1:-1;

	unordered_map<int,int> um;
	rep(i,1,size-1)
	{
		s[i] = s[i-1] + (a[i]=='('?1:-1);
		if(a[i]==')')
		um[s[i]] = i;
	}

	int res = 0;

	rep(i,0,size-1)
	cout<<a[i]<<" "<<i<<" : "<<s[i]<<endl;
	cout<<"\n\n";

	for(auto x : um)
		cout<<x.fi<<" : "<<x.se<<endl;

	rep(i,0,size-2)
	{
		if(a[i]=='(')
		{
			if(um.find(s[i]-1)!=um.end() && um[s[i]-1]>i)
			{
				res = max(res,um[s[i]-1]-i + 1);
			}
		}
	}
	return res;
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a = "(())()(()((";
    cout<<solve2(a)<<endl;

	return 0;
}

