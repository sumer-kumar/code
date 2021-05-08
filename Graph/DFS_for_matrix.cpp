#include <iostream>
using namespace std;
void dfs(int a[][8],int u);
int main(){
//this is graph
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
    dfs(adj,6);


    return 0;
}

void dfs(int a[][8],int u){
    static int visited[8] = {0};
    if(visited[u]==0){
        cout<<u<<" ";
        visited[u] = 1;

        for(int i=1;i<8;i++){
            if(a[u][i]==1&&visited[i]==0)
            dfs(a,i);
        }
    }
}

