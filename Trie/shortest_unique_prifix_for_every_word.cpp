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

int a_size = 26;

struct tnode
{
	tnode* children[26];
	int pre;

	tnode()
	{
	    pre = 0;
		for(int i=0;i<a_size;i++)
		{
			children[i] = NULL;
		}
	}
};
string dfs(tnode* root,string key,string curr,int level);
vector<string> shortest_unique_prefix(int n,string a[]);


/*insert function*/
void insert(tnode* root,string x)
{
	for(int i=0;i<x.size();i++)
	{
		int index = x[i]-'a';

		if(root->children[index]==NULL)
		{
			root->children[index] = new tnode();
		}

		root->pre += 1;
		root=root->children[index];
	}
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n = 4;
	string a[] = {"zebra", "dog", "duck", "dove"};

	vector<string> res = shortest_unique_prefix(n,a);

	return 0;
}

vector<string> shortest_unique_prefix(int n,string a[])
{
	/*make trie*/
	tnode* root= new tnode();

	/*insert into the trie*/
	for(int i=0;i<n;i++)
	{
		insert(root,a[i]);
	}

	vector<string> res;

	/*check for each word*/
	for(int i=0;i<n;i++)
	{
		cout<<dfs(root,a[i],"",0)<<endl;
	}
	return res;
}

string dfs(tnode* root,string key,string curr,int level)
{
	if(root==NULL)
		return curr;
	if(root->pre == 1)
		{

			return curr;
		}

	return dfs(root->children[key[level]-'a'],key,curr+key[level],level+1);
}








/*class Solution
{
    #define s 26

    struct TrieNode
    {
        struct TrieNode* children[s];
        int count;
        bool end;
    };
    struct TrieNode* getNode()
    {
        struct TrieNode* node = new TrieNode;
        for(int i = 0; i < s; i++)
        {
            node->children[i]=NULL;
        }
        node->end=false;
        node->count=0;
        return node;
    }
    
    void insert(TrieNode* root,string key)
    {
        struct TrieNode* temp=root;
        int len = key.length();
        for(int i = 0; i < len; i++)
        {
            if(!temp->children[key[i]-'a'])
                temp->children[key[i]-'a'] = getNode();
            temp=temp->children[key[i]-'a'];
            temp->count++;
        }
        temp->end = true;
    }
    
    string search(TrieNode* root, string key)
    {
        string res;
        struct TrieNode* temp=root;
        int len=key.length();
        for(int i = 0; i < len; i++)
        {
            res.push_back(key[i]);
            temp=temp->children[key[i]-'a'];
            if(temp->count==1)
                break;
        }
        return res;
    }
        
        
        
    // Function to print all prefixes that uniquely
    // represent all words in arr[0..n-1]
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        struct TrieNode* root=getNode();
        for(int i = 0; i< n; i++)
            insert(root, arr[i]);
        
        vector<string>res;
        for(int i = 0; i < n; i++)
            res.push_back(search(root,arr[i]));
        return res;
    }
};
*/