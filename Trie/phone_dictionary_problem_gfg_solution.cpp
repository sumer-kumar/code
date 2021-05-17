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

struct TrieNode{
	unordered_map<char,TrieNode*> child;
	bool isLast;
	TrieNode(){
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;
		isLast = false;
	}
};
TrieNode *root = NULL;

void insert(string s){
	int len = s.length();
	TrieNode *itr = root;
	for (int i = 0; i < len; i++){
		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL){
			nextNode = new TrieNode();
			itr->child[s[i]] = nextNode;
		}
		itr = nextNode;
		if (i == len - 1)
			itr->isLast = true;
	}
}

void insertIntoTrie(string s[],int n){
	root = new TrieNode();
	for (int i = 0; i < n; i++)
		insert(s[i]);
}

void displayContactsUtil(TrieNode *curNode, string prefix, 
                        vector<string> &vec){
	if (curNode->isLast)
		    vec.push_back(prefix);
	for (char i = 'a'; i <= 'z'; i++){
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			displayContactsUtil(nextNode, prefix + (char)i, vec);
	}
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
	insertIntoTrie(contact, n);
	TrieNode *prevNode = root;
    vector<vector<string>> res;
	string prefix = "";
	int len = s.length();
	int i;
	for (i = 0; i < len; i++){
		vector<string> v;
		prefix += (char)s[i];
		char lastChar = prefix[i];
		TrieNode *curNode = prevNode->child[lastChar];
		if (curNode == NULL){
			v.push_back("0");
			res.push_back(v);
			i++;
			break;
		}
		displayContactsUtil(curNode, prefix, v);
		prevNode = curNode;
		res.push_back(v);
	}
	for (; i<len; i++){
	    vector<string> v;
	    v.push_back("0");
	    res.push_back(v);
	}
	return res;
}


int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	

	return 0;
}