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

int p = 0;
/*recursive approach*/
int recur(string s,int i,int j,bool type)
{
	if(i>j)
		return 0;
	if(i==j)
	{
		if(type==true)
			return s[i]=='T';
		return s[i]=='F';
	}


	int ans = 0;
	for(int k=i+1;k<j;k+=2)
	{
		int lt = recur(s,i,k-1,true);
		int lf = recur(s,i,k-1,false);
		int rt = recur(s,k+1,j,true);
		int rf = recur(s,k+1,j,false);

		switch(s[k])
		{
			case '|' :  if(type==true)
					   		ans = ans + lt*rf + lt*rt + lf*rt;
						else
							ans = ans + lf*rf;
						break;
			case '&' :	if(type==true)
							ans = ans + lt*rt;
						else
							ans = ans + lt*rf + lf*rf + lf*rt;
						break;
			case '^' :	if(type==true)
							ans = ans + lt*rf + lf*rt;
						else
							ans = ans + lt*rt + lf*rf;
						break;
		}
	}
	return ans;
}

/*memoization*/

int dp[201][201][2];
int memo(string s,int i,int j,int type)
{
	if(i>j)
		return 0;
	if(i==j)
	{
		if(type==1)
			return s[i]=='T';
		return s[i]=='F';
	}
	if(dp[i][j][type]!=-1)
		return dp[i][j][type];


	int ans = 0;
	for(int k=i+1;k<j;k+=2)
	{
		int lt,lf,rt,rf;

		if(dp[i][k-1][1]!=-1)
			lt = dp[i][k-1][1];
		else
			lt = memo(s,i,k-1,1);
		
		if(dp[i][k-1][0]!=-1)
			lf = dp[i][k-1][0];
		else
			lf = memo(s,i,k-1,0);
		
		if(dp[k+1][j][1]!=-1)
			rt = dp[k+1][j][1];
		else
			rt = memo(s,k+1,j,1);
		
		if(dp[k+1][j][0]!=-1)
			rf = dp[k+1][j][0];
		else
			rf = memo(s,k+1,j,0);

		switch(s[k])
		{
			case '|' :  if(type==1)
					   		ans = ans + lt*rf + lt*rt + lf*rt;
						else
							ans = ans + lf*rf;
						break;
			case '&' :	if(type==1)
							ans = ans + lt*rt;
						else
							ans = ans + lt*rf + lf*rf + lf*rt;
						break;
			case '^' :	if(type==1)
							ans = ans + lt*rf + lf*rt;
						else
							ans = ans + lt*rt + lf*rf;
						break;
		}
	}
	return dp[i][j][type] = ans;
}


/***********************************GFG SOL*******************************/
int countWays(int N, string S){
        int i,j,len;
    	int dpTrue[N][N],dpFalse[N][N];
    
    	for(i = 0;i < N;i+=2){
    		if(S[i]=='T'){
    			dpTrue[i][i]=1;
    			dpFalse[i][i]=0;
    		}else{
    			dpTrue[i][i]=0;
    			dpFalse[i][i]=1;
    		}
    	}
    	int x=2;
    	while(x < N){
    		for(i = 0;(i+x) < N;i+=2){
    			dpTrue[i][i+x] = dpFalse[i][i+x]=0;
    			for(j = i+1;j < (i+x);j+=2){
    				if(S[j]=='|'){
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x])%1003;								
    
    				}else if(S[j]=='&'){
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    					dpFalse[i][i+x] =(dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x] +
    									dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
    				}else{
    					dpTrue[i][i+x] = (dpTrue[i][i+x] + 
    									dpFalse[i][j-1]*dpTrue[j+1][i+x] +
    									dpTrue[i][j-1]*dpFalse[j+1][i+x])%1003 ;
    					dpFalse[i][i+x] = (dpFalse[i][i+x] + 
    									dpFalse[i][j-1]*dpFalse[j+1][i+x] +
    									dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003 ;
    				}
    			}
    		}
    	    x=x+2;
    	}
    	return dpTrue[0][N-1]%1003;
    }

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    
    memset(dp,-1,sizeof(dp));

    // cout<<recur(s,0,s.size()-1,true)<<endl;
    cout<<memo(s,0,s.size()-1,1)<<endl;


	return 0;
}

