#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> anagramsLIST(vector <string> a);


int main()
{
    vector<string> s = {"cat", "dog", "tac", "god", "act"};
    vector<vector<string>> vs = anagramsLIST(s);

    for(int i=0;i<vs.size();i++)
    {
        for(int j=0;j<vs[i].size();j++)
        {
            cout<<vs[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

vector<vector<string>> anagramsLIST(vector <string> a)
{
    vector<vector<string>> final_list;
    vector<string> dam; // dam i like it

    int size = a.size();
    vector<pair<string,int>> pair_vector;
    string s;
    pair<string,int> pair_string;
    //what i am doing here is
    //i sort a particular string
    //and pair it with the value of 
    for(int i=0;i<size;i++)
    {   
        s = a[i];
        sort(s.begin(),s.end());
        pair_string.first = s;
        pair_string.second = i;

        pair_vector.push_back(pair_string);
    }

    sort(pair_vector.begin(),pair_vector.end());

    int j = 0; //distinct elements
    dam.push_back(a[pair_vector[0].second]);

    for(int i=1;i<size;i++)
    {
        if(pair_vector[i-1].first == pair_vector[i].first)
        {
            dam.push_back(a[pair_vector[i].second]);
        }
        else
        {
            final_list.push_back(dam);
            dam.clear();
            dam.push_back(a[pair_vector[i].second]);
        }

    }
    final_list.push_back(dam);

    //arranging order
    for (int i = 0; i < final_list.size(); i++)
    {
        for (int j = 1; j < final_list[i].size()-i; j++)
        {
            if (final_list[i][final_list[i]. - 1] > final_list[j][final_list[j].size() - 1])
            // swap(final_list[i],final_list[j]);
            final_list[i].swap(final_list[j]);
        }
    }

    return final_list;
}






