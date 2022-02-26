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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
typedef ListNode node;
node* create(vi &a)
{
	node* head=NULL;
	node* t;

	for(int x : a)
	{
		if(head==NULL)
		{
			head = new node(x);
			t = head;
		}
		else
		{
			t->next = new node(x);
			t=t->next;
		}
	}

	return head;
}


void print(node* t)
{
	while(t)
	{
		cout<<t->val<<" ";
		t=t->next;
	}
	cout<<endl;
}

node* merge(node* a,node* b)
{
	if(!a)
		return b;

	if(!b)
		return a;

	if(a->val < b->val)
	{
		a->next = merge(a->next,b);
		return a;
	}

	b->next = merge(a,b->next);
	return b;
}

//divide the linked list into half and returns the head of second half linkedlist
node* half(node* head)
{
	if(!head | !head->next)
		return head;

	node* slow = head;
	node* fast = head->next;

	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	return slow;
}

node* recur(node* head)
{
	if(head==NULL || head->next==NULL)
		return head;

	node* mid = half(head);
	node* first = head;
	node* second = mid->next;
	
	mid->next=NULL;

	first = recur(first);
	second = recur(second);

	return merge(first,second);
}

node* solve(node* head)
{
	return recur(head);
}


/*main-------------------------------------------->*/
int main() {
	defile();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {7,6,5,4,3,2,1};
    node* head = create(a);
    print(head);

    head = solve(head);

    print(head);

	return 0;
}

