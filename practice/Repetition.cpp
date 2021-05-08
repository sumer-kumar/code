#include <iostream>
using namespace std;

int main(){
    int count=0;
    int maxCount =0;
    string str;

    getline(cin,str);

    for(int i=0;i<str.size();i++)
    {
        if(str[i]==str[i+1])
        {
            count++;
            if(count>maxCount)
            {
                maxCount=count;
            }
        }
        else
        {
            count=0;
        }
        
    }

    cout<<(maxCount+1);
    return 0;
}