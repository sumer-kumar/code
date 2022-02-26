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
bool diff_by_one(string a,string b);
int word_ladder(string &start,string &end, vector<string> &wordList);


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		
	vector<string> wordList = {"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"};
	/* Start = ABCV
       End = EBAD*/
	string start = "POON";
	string end = "PLEA";

	cout<<word_ladder(start,end,wordList)<<endl;

	return 0;
}

bool diff_by_one(string a,string b)
{
	int cnt =0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
			cnt++;
	}
	return cnt==1;
}

int word_ladder(string &start,string &end, vector<string> &wordList)
{
	unordered_map<string,int> um;
	for(int i=0;i<wordList.size();i++)
	{
		um[wordList[i]] = 0;
	}

	if(um.find(end)==um.end() || start==end) return 0;


	unordered_map<string,vector<string>> res;

	/*if start string is not present in the wordlist*/
	if(um.find(start)==um.end())
	{
		for(auto x = um.begin();x!=um.end();x++)
		{
			if(diff_by_one(start,x->first))
			{
				res[x->first].push_back(start);
				res[start].push_back(x->first);
			}
		}
	}


	/*map is ready */
	for(auto x = um.begin();x!=um.end();x++)
	{
		for(auto p = x ;p!=um.end();p++)
		{	
			if(diff_by_one(x->first,p->first))
			{
				res[x->first].push_back(p->first);
				res[p->first].push_back(x->first);
			}
		}
	}

	queue<string> q;
	q.push(start);
	um[start] = 1;

	while(!q.empty())
	{
		string curr = q.front();
		q.pop();

		if(curr==end)
		{
			return um[curr];
		}

		for(string x : res[curr])
		{
			/*not visited*/
			if(um[x]==0)
			{
				um[x] = um[curr]+1;
				q.push(x);
			}
		}
	}
	return 0;
}


