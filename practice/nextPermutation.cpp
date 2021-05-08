#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int>& str ,int start,int end)
{
    while(start<end){
        swap(str[start++],str[end--]);
    }
}

int binarySearch(vector<int>&a,int low ,int high,int match){
    int mid; // to find the mid of rang between high and low

    while(low<=high){
        mid = (high - low) / 2 + low;

        if(a[mid]>match)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
        
    }
    return mid;
}

void nextPermutation(vector<int>&a){
    int size = a.size();
  
   
        int i = size-2;//used when comparing adjacent elements


        /**
         * Compare ech element with next one 
         * if left element is greater than right element than continue
         * and stop the loop if this case is not satisfied  
         * */
        while(i>=0&a[i]>=a[i+1])
            i--;

        if(i<0) //of combination is made as highest element
        {
            sort(a.begin(),a.end());
            cout << "[";
            for (int i = 0; i < size; i++)
                cout << a[i] << ",";
            cout << "\b]";
            return ;
        }
        else{//when there exit next permutation
        reverse(a,i+1,size-1);
        
        int index = binarySearch(a,i+1,size-1,a[i]); //index of next smalles element
        
        swap(a[i],a[index]); //swapping
        }
    //output
    cout<<"[";
        for (int i = 0; i < size; i++)
            cout << a[i] << ",";
        cout << "\b]";
    }





int main(){
    vector<int> a{3,2,1};
    nextPermutation(a);

    return 0;
}