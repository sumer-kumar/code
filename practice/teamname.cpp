#include <bits/stdc++.h>
using namespace std;

#define max 30000
void hashing(int size);
int names(int size);
void initialize();
unordered_set<char> prefix; //first letter
unordered_set<string> words; //full words
unordered_set<string> postfix;

string s[max];

int main(){
    int test;
    cin>>test;
    int size;
    while(test--){
        initialize();
        cin>>size;
        for(int i=0;i<size;i++){
            cin>>s[i];
        }
        hashing(size);
        cout<<names(size)<<endl;
        prefix.clear();
        postfix.clear();
        words.clear();
    }
    return 0;
}

void hashing(int size){
    for(int i=0;i<size;i++){
        words.insert(s[i]); //hashing word
        prefix.insert(s[i][0]); //hashing first letter
        postfix.insert(s[i].substr(1,s[i].size()-1)); //hashing word without first letter
    }
}
int names(int size){
   int count = prefix.size()*postfix.size();
    char ch;
    string str;
    for(auto it = prefix.begin();it!=prefix.end();it++){//loop for set of first letter
        ch = *it;
        for(auto jt = postfix.begin();jt!=postfix.end();jt++){
            str = *jt;
            if(words.find(ch+str)!=words.end())
            count--;            
        }
    }
    return count;
}
void initialize(){
    for(int i=0;i<max;i++){
        s[i] = "";
    }
}

