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

bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;
    return ret;
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	return 0;
}

