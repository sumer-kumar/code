#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> sumer;

    for(int i=0;i<=10;i++)
    {   
        vector<int> v;

        for(int j=0;j<=i;j++)
        {
            v.push_back(j);

        }
        sumer.push_back(v);
        cout<<endl;
    }
    for(int i=0;i<sumer.size();i++){
        for(int j=0;j<sumer[i].size();j++)
        cout<<sumer[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}