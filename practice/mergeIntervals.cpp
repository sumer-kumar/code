#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<vector<int>> mergeIntervals(int a[][2], int n) ;

int main()
{
    int a[][2] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    
    
    vector<vector<int>> v =  mergeIntervals(a,4);
    for(int i=0;i<v.size();i++){

            cout<<"["<<v[i][0]<<","<<v[i][1]<<"] ";
    }
    
    return 0;
}

vector<vector<int>> mergeIntervals(int a[][2],int n){
    multimap<int,int> m;  //used to store the data in sorted order
    
    //in question we have to do this for 2d vector
    vector<vector<int>> sumer;

    pair<int,int> p; //used to insert in map

    for(int i=0;i<n;i++){
        p.first = a[i][0]; //wanted to store lower bound as key value in map
        p.second = a[i][1]; //second value mappd with forst

        m.insert(p); //inserting that pair
    }
    
    auto it = m.begin();

    int lb = it->first;
    int ub = it->second;

    vector<int> v(2);
    it++;
    for(;it!=m.end();it++){
        if(it->first<=ub){
           // ub = it->second;
           ub = max(ub,it->second);
        }
        else
        {
            //cout<<"["<<lb<<","<<ub<<"] ";

            v[0] = lb;
            v[1] = ub;
            
            sumer.push_back(v);

            lb = it->first;
            ub = it->second;   
        }

    }
    v[0] = lb;
    v[1] = ub;

    sumer.push_back(v);

    return sumer;
}












