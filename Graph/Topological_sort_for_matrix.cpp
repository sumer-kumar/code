#include <iostream>
using namespace std;
void topologicalSort(int a[][8],int u);
int visited[8] = {0};
int main(){
//this is graph
    int adj[][8]={//0,1,2,3,4,5,6,7
         /*0*/     {0,0,0,0,0,0,0,0},
         /*1*/     {0,0,1,0,1,0,0,0},
         /*2*/     {0,0,0,1,0,0,0,0},
         /*3*/     {0,0,0,0,0,1,0,0},
         /*4*/     {0,0,0,0,0,1,0,0},
         /*5*/     {0,0,0,0,0,0,1,0},
         /*6*/     {0,0,0,0,0,0,0,0},
         /*7*/     {0,0,0,0,0,1,0,0}
                  };
    for(int i=1;i<8;i++)
    if(visited[i]==0)
    topologicalSort(adj,i);
//output will be in reversing order

    return 0;
}

void topologicalSort(int a[][8],int u){
    
    if(visited[u]==0){

        visited[u] = 1;

        for(int i=1;i<8;i++){
            if(a[u][i]==1&&visited[i]==0)
            topologicalSort(a,i);
        }
    }
    cout<<u<<" ";
}

