#include <bits/stdc++.h>
using namespace std;

string takeinput();
double converter(string s);

int main()
{
    string t = "04:12PM";
    cout<<converter(t);
    return 0;
}

string takeinput()
{
    string time = "";
    char ch;
    for (int i = 0; i < 7; i++)
    {
        cin >> ch;

        time.push_back(ch);
    }
    return time;
}
double converter(string s)
{
    string str = s.substr(0, 5);
    str[2] = '.';

    double time = stod(str);
    if (s[5] == 'P')
    {
        if (time < 12)
        {
            time += 12;
        }
    }
    else if (time >= 12)
    {
        time -= 12;
    }
    return time;
}