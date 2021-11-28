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


struct node {
	int speed;
	int position;
	int len;

	node()
	{
		speed=1;
		position=0;
		len=0;
	}

	node(int speed,int position,int len)
	{
		this->speed = speed;
		this->position = position;
		this->len = len;
	}
};

string getHash(int speed,int position)
{
	return to_string(speed)+" "+to_string(position);
}

int solve(int target)
{
	queue<node*> q;

	q.push(new node());

	unordered_set<string> st;

	while(!q.empty())
	{
		node* t = q.front();
		q.pop();

		if(t->position==target)
			return t->len;

		string h1 = getHash(t->speed*2,t->position+t->speed);
		string h2 = getHash(t->speed>0?-1:1,t->position);

		/*when accelarate*/
		if(abs(t->position+t->speed - target)<target && st.find(h1)==st.end())
		{
			st.insert(h1);
			q.push(new node(t->speed*2,t->position+t->speed,t->len+1));
		}

		/*when reverse*/
		if(abs(t->position-target)<target && st.find(h2)==st.end())
		{
			st.insert(h2);
			q.push(new node(t->speed>0?-1:1,t->position,t->len+1));
		}
	}

	return -1;
}
/* if (Math.abs(cur.pos + cur.speed - target) < target && !visited.contains(s1)) {
    visited.add(s1);
    queue.add(new CarInfo(cur.pos + cur.speed, cur.speed * 2));
}
if (Math.abs(cur.pos - target) < target && !visited.contains(s2)) {
    visited.add(s2);
    queue.add(new CarInfo(cur.pos, cur.speed > 0 ? -1 : 1));
}*/

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target = 6;

    cout<<solve(target)<<endl;

	return 0;
}

