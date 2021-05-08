#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 256
int bad_match[MAX_SIZE];

void badMatch(string pat, int bad_match[])
{
    int size = pat.size();

    //filling bad match array with size of the string
    for (int i = MAX_SIZE - 1; i >= 0; i--)
        bad_match[i] = size;

    //filling the bad match array with
    for (int i=0;i<size;i++)
    {
        bad_match[(int)pat[i]] = size - i - 1; 
    }
    bad_match[(int)pat[size-1]] = size;
}

vector<int> boyerMooreSearch(string pat, string txt)
{

    badMatch(pat, bad_match);

    int sizep = pat.size(); //pattern size
    int sizet = txt.size(); //text size

    vector<int> matches;

    int s = 0; //shift
    int j;
    while (s+sizep<=sizet)
    {
        j = sizep - 1; //pointing to last position of the pattern string

        while (j >= 0 && txt[s + j] == pat[j])
            j--;

        if (j < 0) //when matches
        {
            matches.push_back(s);

            //shifting the shift when there is a match
            s += (s + sizep < sizet) ? bad_match[(int)txt[s + sizep]] : 1;
        }

        else //when does not matches
        {
            s += bad_match[(int)txt[s + j]];
        }
    }
    return matches;
}

int main()
{
    vector<int> v = boyerMooreSearch("abc", "abcabcbcabbbcbacbabcbbabc");
    cout<<v.size()<<endl;

    for(auto x : v)
    cout<<x<<",";
    cout<<"\b";
    return 0;
}

