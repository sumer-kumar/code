#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(string s);

int main()
{
    cout << minimumSwaps("[[][]]") << endl;
    return 0;
}

int minimumSwaps(string s)
{
    int total = 0;
    queue<int> q;
    int size = s.size();

    //enqueing indexes of '['
    for(int i=0;i<size;i++)
        if(s[i]=='[')
            q.push(i);

    int count = 0;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='[')
        count++;

        else 
        count--;

        if(count<0) //when there is ] bracket without balancing or unbalancing condition
        {
            while(i>q.front())
                q.pop();
                 
            total += q.front()-i;
            swap(s[i],s[q.front()]);
            q.pop();
            count = 1;
        }
    }
    return total;
}