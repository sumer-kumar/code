#include <bits/stdc++.h>
using namespace std;

string ditinctSTRING(string s);

int main()
{
    cout << ditinctSTRING("aadabv") << endl;
    return 0;
}

string ditinctSTRING(string s)
{
    string res = "";
    priority_queue<pair<int,char>> pq;
    pair<int,char> p;
    unordered_map<char,int> um;
    int size = s.size();
    for(int i=0;i<size;i++)
        um[s[i]]++;

    for(auto i = um.begin();i!=um.end();i++)
    {
        p.first = i->second;
        p.second = i->first;
        if(p.first>(size+1)/2)
        {
            return "could not possible";
        }
        pq.push(p); //pushing pair in priority queue
    }
    stack<pair<int,char>> stk;
    for(int i = 0;i<size;i++)
    {   //when stack is not empty
        if(stk.empty())
        {
            res.push_back(pq.top().second);
            pair<int,char> tp = pq.top();
            tp.first--;
            stk.push(tp);
            pq.pop();
        }   
        else
        {
            res.push_back(pq.top().second);

            pair<int, char> tp = pq.top();
            pq.pop();
            tp.first--;
            pq.push(tp);
            pq.push(stk.top());
            stk.pop();
        }

    }

    return res;
}