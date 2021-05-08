#include <bits/stdc++.h>
using namespace std;
bool isIsomophic(string a,string b);

int main()
{
    cout<<isIsomophic("rfkqyuqf",
                      "jkxyqvnr")<<endl;
    return 0;
}

bool isIsomophic(string a,string b)
{
    int sizea = a.size();
    int sizeb = b.size();
    if(sizea != sizeb)
    return false;

    const int MAX_CHARACTERS = 256;
    int hasha[MAX_CHARACTERS] = {0}; //it will map index of character if a with equivalent character of b
    int hashb[MAX_CHARACTERS] = {0}; //it will map index of character if b with equivalent character of a 

    for(int i=0;i<sizeb;i++)
    {
        if(hashb[(int)b[i]] == 0)
        {
            hashb[(int)b[i]] = (int)a[i];
        }
        else
        {
            if(hashb[(int)b[i]]!=a[i])
            return false;
        }
        
    }

    for(int i=0;i<sizea;i++)
    {
        if(hasha[(int)a[i]]==0)
        {
            hasha[(int)a[i]] = (int)b[i];
        }
        else
        {
            if(hasha[(int)a[i]]!=b[i])
            return false;
        }
    }    
    return true;
}