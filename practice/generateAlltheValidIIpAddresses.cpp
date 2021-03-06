#include <bits/stdc++.h>
using namespace std;


bool validIPchecker(string ip);
void generateAlltheIPs(string ip);

int main()
{
    generateAlltheIPs("25525511135");
    return 0;
}

void generateAlltheIPs(string ip)
{
    //read the properties of ipv4 ip address
    int size = ip.size();

    /*it will only work on range of strings of 
        size greater than equal to one
        size less than equal to 12*/
    if(size>12||size<4)
    {
        cout<<"invalid string for ip"<<endl;
        return;
    }

    string check = ip;

    /*plot all the possible three points in the strings
        and check whether they are valid or not*/
    for(int i=1;i<size-2&&i<=3;i++)
    {
        for(int j=i+1;j<size-1&&j<=i+3;j++)
        {
            for(int k=j+1;k<=j+3&&k<size;k++)
            { //255.255.111.35
              //1.1.1.1 //1111
              check.insert(k,".");
              check.insert(j,".");
              check.insert(i,".");

              cout<<check<<"-->"<<validIPchecker(check)<<endl;
              check = ip; 
            }
        }
    }
}

bool validIPchecker(string ip)
{
    vector<string> vec; //to store the splited string with dots
    int size = ip.size();


    string part="";
    
    /*split the string whenever "."(dot) occurs */
    for(int i=0;i<size;i++)
    {   
        if(ip[i]=='.'||i==size-1)
        {
            vec.push_back(part);
            part = "";
        }
        else 
        {
            part.push_back(ip[i]);
        }
    }

    //push the last part
    vec[3].push_back(ip[size-1]);

    for(int i=0;i<vec.size();i++)
    {
        // cout<<i<<".("<<vec[i]<<")"<<endl;

        if(vec[i].size()>4)
        return false;
        if(vec[i].size()>1&&vec[i][0]=='0')
        return false;

        //stoi for string to integer
        if(stoi(vec[i])>255)
        return false;
    }
    return true;
}