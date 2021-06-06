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

class Maxheap{
	private :
	vi a;
	int size;
	int capacity;
	int parent(int i){return (i)/2;}
	int left(int i){return 2*i;}
	int right(int i){return 2*i+1;}

	public :
	Maxheap()
	{
		size = 1;
		capacity = 1001;
		vi x (capacity,0);
		a = x;
	}

	int top(){return a[1];}
	void insert(int x);
	void pop();
	void show();
};

void Maxheap ::insert(int x )
{
	int i=size;
	a[i]=x;
	size++;

	while(i!=1 && a[parent(i)] < a[i])
	{
		swap(a[parent(i)],a[i]);
		i=parent(i);
	}
}

void Maxheap :: show()
{
	rep(i,0,size-1)
	cout<<a[i]<<" ";
	cout<<endl;
}

void Maxheap :: pop()
{
	swap(a[1],a[size-1]);
	size--;
	int i=1;
	int j=2*i; /*initially poiting to left*/

	while(j<size-1)
	{
		if(a[j]<a[j+1])
			j++;
		if(a[i]<a[j])
		{
			swap(a[i],a[j]);
			i=j;
			j=2*j;
		}
		else
			break;
	}
}

/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    Maxheap hp;

    vi a(n);
    rep(i,0,n-1)
    {
    	cin>>a[i];
    	hp.insert(a[i]);
    }
    hp.pop();
    hp.show();
	return 0;
}

