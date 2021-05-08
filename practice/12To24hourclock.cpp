#include <bits/stdc++.h>
using namespace std;

string takeinput();
double converter(string s);
double stringToDouble(string s); 
int main()
{   int test;
    //cout<<stringToDouble("4.45")<<endl;
    
    string p;
    string t1;
    string t2;
    double timep;
    cin>>test;
    while(test--){
        int size;
        p = takeinput();
        cin>>size;
        timep=converter(p);
        while(size--){

            t1 = takeinput();
            cin>>ws;
            t2 = takeinput();

            cout<<(timep>=converter(t1)&&timep<=converter(t2));

        }
       cout<<endl;
    }
    return 0;
}

string takeinput(){
    string time = "";
    char ch;
    for(int i=0;i<7;i++)
    {
        cin>>ch;

        time.push_back(ch);
    }
    return time;

}
double converter(string s){
    string str = s.substr(0,5);
    str[2]='.';

    double time = stringToDouble(str);

    if(s[5]=='P'){
        if(time<12){
            time+=12;
        }
    }
    else if(time>=12){
        time-=12;
    }
    return time;
}
double stringToDouble(string s){
    double value=0;
    bool dotEncountered = false;
    double afterDot=10;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            dotEncountered = true;
            continue;
        }
        if(dotEncountered){
            value = value + (s[i]-'0')/afterDot;
            afterDot*=10;
        }
        else
        {
            value = value*10 + (s[i]-'0'); 
        }
        
    }


return value;
}