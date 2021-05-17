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

struct hnode
{
	char data;
	hnode* left;
	hnode* right;
	int freq;

	/*constructor*/
	hnode(char data,int freq)
	{
		this->data = data;
		this->freq = freq;
		left = right = NULL;
	}
};
/*comparator*/
struct cmp
{
    bool operator()(hnode* l, hnode* r)
    {
        return (l->freq > r->freq);
    }
};
void preorder(hnode* root,vector<string> &res,string curr="")
{
	/*base condtition*/
	if(!root) return;
	if(root->data!='#')
	{
		cout<<curr<<endl;
		res.push_back(curr);
	}

	preorder(root->left,res,curr+"0");
	preorder(root->right,res,curr+"1");
}

void huffman_code(string sent,vector<int> &freq)
{
	int size = freq.size();

	/*make min heap*/
	priority_queue<hnode*,vector<hnode*>, cmp> pq;

	/*push all nodes in it*/
	for(int i=0;i<size;i++)
	{
		pq.push(new hnode(sent[i],freq[i]));
	}

	hnode* left;
	hnode* right;
	hnode* root;

	/*do this when we have left with only a single element in min heap
		i.e to root node*/

	while(pq.size()!=1)
	{
		/*take smallest into left*/
		left = pq.top();
		pq.pop();

		/*and second smallest to right*/
		right = pq.top();
		pq.pop();

		/*assign root*/
		root = new hnode('#',left->freq+right->freq);

		root->left = left;
		root->right = right;

		/*push the root node into priority queue*/
		pq.push(root);
	}

	/*make preorder traveral for getting the data*/
	vector<string> res;	

	preorder(root,res);
}

int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	// char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    string data = "abcdef";
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    vector<int> f(freq,freq+6);

    int size = sizeof(data) / sizeof(data[0]);	

    huffman_code(data,f);

	return 0;
}
