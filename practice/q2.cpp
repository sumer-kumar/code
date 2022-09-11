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


bool solve(int n)
{
    int t = n;
    int res = 0;
    while(t>0)
    {
        if(t&1)
        {
            res = (res<<1) | 1;
        }
        else
            res<<=1;
        t>>=1;
    }
    return res==n;
}


node* solve(node* head,int num)
{
    stack<node*> st;
    bool flag = false;
    for(node* t = head;t!=NULL;t=t->next)
    {
        if(st.empty())
            st.push(t);
        else if(st.top()->val + t->val == num)
        {
            flag = true;
            st.pop();
        }
        else 
            st.push(t);
    }

    if(flag==true)
    {
        node* t = head;
        while(!t->next)
            t=t->next;
        t->next=new node(num);
        t->next->next = NULL;
        return head;
    }

    if(st.empty())
        return NULL;
    if(st.size()==1)
    {
        st.top()->next=NULL;
        return st.top();
    }

    vector<node*> res;
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    node* head = res[0];
    for(int i=1;i<res.size();i++)
    {
        res[i-1]->next = res[i];
        res[i]=NULL;
    }

    return head;
}


/*main-------------------------------------------->*/
int main() {
    defile();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<solve(4)<<endl;

    return 0;
}

