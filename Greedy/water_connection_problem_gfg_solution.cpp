class Solution
{
    public:
    
    // number of houses and number
    // of pipes
    int n, p;

    // Array rd stores the
    // ending vertex of pipe
    vector<int> rd;

    // Array wd stores the value
    // of diameters between two pipes
    vector<int> wt;

    // Array cd stores the
    // starting end of pipe
    vector<int> cd;


    int ans;

    int dfs(int w)
    {
    	if (cd[w] == 0)
    		return w;
    	if (wt[w] < ans)
    		ans = wt[w];
    	return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        this->n=n;
        this->p=p;
        rd=vector<int>(n+1);
        wt=vector<int>(n+1);
        cd=vector<int>(n+1);
        vector<vector<int>> res;
        
        int i = 0;
       
    	while (i < p) {
    
    		int q = a[i], h = b[i],
    			t = d[i];
    
    		cd[q] = h;
    		wt[q] = t;
    		rd[h] = q;
    		i++;
    	}

        
    	for (int j = 1; j <= n; ++j)
    
    		/*If a pipe has no ending vertex
    		but has starting vertex i.e is
    		an outgoing pipe then we need
    		to start DFS with this vertex.*/
    		if (rd[j] == 0 && cd[j]) {
    			ans = 1000000000;
    			int w = dfs(j);
    
    			// We put the details of component
    			// in final output res array
    			
    			res.push_back({j,w,ans});
    	}
    
        return res;
    }
};