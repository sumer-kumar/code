#include <bits/stdc++.h>
using namespace std;

string mobileKeypadSequence(string s);
string keypadCode(char ch);


int main()
{
    cout<<"\b"<<mobileKeypadSequence("sumer")<<endl;

    return 0;
}

string keypadCode(char ch)
{
    string code[] = {
        "2","22","222", 
        "3","33","333", 
        "4","44","444", 
        "5","55","555", 
        "6","66","666", 
        "7","77","777","7777", 
        "8","88","888", 
        "9","99","999","9999"
    };

    return code[ch - 'a'];
}

string mobileKeypadSequence(string s)
{
    string code = "";

    for(int i=0;i<s.size();i++)
    {
        code+=","+keypadCode(s[i]);
    }
    return code.substr(1);
}