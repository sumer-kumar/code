#include <bits/stdc++.h>
using namespace std;
int numberOfCustomerWhoDidnotGetComputer(int number,string s) ;

// cout << runCustomerSimulation(2, "ABCADEBCED") << endl;
// cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
// cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
// cout << runCustomerSimulation(1, "ABCBCA") << endl;
// cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
int main()
{
    // cout<<numberOfCustomerWhoDidnotGetComputer(2,"ABCADEBCE")<<endl;
    cout << numberOfCustomerWhoDidnotGetComputer(2, "ABBAJJKZK") << endl;
    cout << numberOfCustomerWhoDidnotGetComputer(3, "GACCBDDBAGEE") << endl;
    cout << numberOfCustomerWhoDidnotGetComputer(3, "GACCBGDDBAEE") << endl;
    cout << numberOfCustomerWhoDidnotGetComputer(1, "ABCBCA") << endl;
    cout << numberOfCustomerWhoDidnotGetComputer(1, "ABCBCADEED") << endl;
    return 0;
}

int numberOfCustomerWhoDidnotGetComputer(int number, string s) //number od number of computers
{
    int res = 0;
    int hash[256] = {0};
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(hash[(int)s[i]]==0)//if customer is entering in the shop
        {
            if(count < number)
            {
                count++;
                hash[(int)s[i]] = 1;
            }
            else
            {
                hash[(int)s[i]] = -1;
                res++;
            }
        }
        else if(hash[(int)s[i]]!=-1)//when they exit
        {
            count--;
        }

    }
    return res;
}