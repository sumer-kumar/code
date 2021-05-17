struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

class Solution
{
	public:
	    void getCodes(struct MinHeapNode* root, string str,vector<string> &res)
        {
            if (!root)
                return;
            if (root->data != '$'){
                res.push_back(str);
            } 
            getCodes(root->left, str + "0",res);
            getCodes(root->right, str + "1",res);
        }
        
        
        /*the representive function*/
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    struct MinHeapNode *left, *right, *top;
            
            /*min heap*/
            priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
            for (int i = 0; i < N; ++i)
                minHeap.push(new MinHeapNode(S[i], f[i]));
            while (minHeap.size() != 1)
            {
                left = minHeap.top();
                minHeap.pop();
                right = minHeap.top();
                minHeap.pop();
                top = new MinHeapNode('$', left->freq + right->freq);
                top->left = left;
                top->right = right;
                minHeap.push(top);
            }
            vector<string> res;
            getCodes(minHeap.top(), "",res);
            return res;
		}
};