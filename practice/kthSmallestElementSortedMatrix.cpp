#include <bits/stdc++.h>
using namespace std;
//node
struct node{
    int data; //value
    int r; //row index
    int c;//column index
};
//comparator class
class cmp{
    public :
    bool operator()(const node &a,const node &b){
        return a.data>b.data;
    }
};
int kthSmallest(int a[][4],int n,int k);


//main-----------------------------------------------------------------
int main(){

    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };

    cout<<kthSmallest(mat,4,7);
    return 0;
}

int kthSmallest(int a[][4],int n,int k){
    priority_queue<node,vector<node>,cmp> pq;

    node t;//points to top of the priority queue

    //initialsing heap with first row
    for(int i=0;i<n;i++){
        pq.push({a[0][i],0,i}); //using direct inserting in struct
    }
    /**
     * Now what we are going to do
     * 1.every time we pop the top element of the min heap
     * 2.and push the element of next row and same column
     * 3.if top is from last row
     * 4.do nothing
     * 5.else contiue do this
     * 6.when the loop runs out the top element will be the kth smallest element of the matrix
     * */
    node temp;
    for(int i=0;i<k;i++)
    {
        temp = pq.top();
        pq.pop();

        if(temp.r<n-1){
            pq.push({a[temp.r+1][temp.c],temp.r+1,temp.c});
        }
        
    }
    return temp.data;

}











