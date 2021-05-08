#include <bits/stdc++.h>
using namespace std;

//function-----------------------
void longestPalindromeSubstring(string s);

//main---------------------------
int main()
{
    int test;
    cin>>test;
    string s;
    while (test--)
    {
        cin>>s;
        
    }
    longestPalindromeSubstring("aaaabbaa");
    return 0;
}

void longestPalindromeSubstring(string s)
{
    int start;
    int n = s.size();
    bool t[n][n];
    int max = 1; //maximum is one because every symbol is itself a palindrome

    //filling with false
    memset(t, 0, sizeof(t));

    //single symbol itself is a palindrome
    for (int i = 0; i < n; i++)
        t[i][i] = true;

    //to checking palindrome of length 2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            t[i][i + 1] = true;
            start = i;
            max = 2;
        }
    }

    //here comes the main part
    //checking palindrome for length 2
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1; //ending position
            if (s[i] == s[j] && t[i + 1][j - 1] == true)
            {
                t[i][j] = true;
                start = i;
                max = max > k ? max : k;
            }
        }
    }
    cout << s.substr(start, start + max - 1) << endl;
}
