#include <iostream>
#include <queue>

using namespace std;
void bfs(int a[][8],int startingPoint);


int main(){
//this is graph
/**
 *      1---2
 *      |   |
 *      3---4
 *       \ /
 *        5
 *       / \
 *      6   7
 */
    int adj[][8] = {
                   {0,0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0,0},
                   {0,1,0,0,1,0,0,0},
                   {0,1,0,0,1,1,0,0},
                   {0,0,1,1,0,0,0,0},
                   {0,0,0,1,1,0,1,1},
                   {0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,1,0,0}
                   };

    bfs(adj,3);
    return 0;
}

void bfs(int a[][8],int startingPoint){
    //array to visiting
    int visited[8] = {0};
    //for queuing
    queue<int> q;
    //printing starting point
    cout<<startingPoint<<" ";
   
    //enqueuing
    q.push(startingPoint);
    visited[startingPoint]=1;
    int u ; //for row 
    while(!q.empty()){
        
        u = q.front();
        q.pop();

        for(int v=1;v<8;v++){
            if(a[u][v]==1&&visited[v]==0){ // if there is a edge and node is unvisited
                cout<<v<<" ";
                q.push(v);
                visited[v]=1;
            }
        }
    }
}









