#include <bits/stdc++.h>
using namespace std;

int longestRecurringSubsequence(string s1);

int main()
{
    cout << longestRecurringSubsequence("aabb") << endl;
    return 0;
}
//its working fine well done lad
int longestRecurringSubsequence(string s)
{
    int size = s.length(); //size of
    // int size2 = s2.length();

    int lcs[size + 1][size + 1]; //matrix
    //size is taken one because first row and first column should be filled with zero only
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
                // continue;
            }

            else if (s[i - 1] == s[j - 1]&&i!=j)
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }

            else
            {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }
    return lcs[size][size];
}