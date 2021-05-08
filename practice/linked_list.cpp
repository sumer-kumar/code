#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int data;
    struct node* next;
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node* x = new node();
    x->data = 3;
    x->next = NULL;
    cout<<x->data;    
    
    return 0;
}