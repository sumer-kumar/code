#include <bits/stdc++.h>
using namespace std;

#define max 10
int maxAreaRectangleMatrix(int a[][4],int n,int m);
int maxAreaHistogram(int a[],int size);

int main(){
    int A[][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    cout<<maxAreaRectangleMatrix(A,4,4);

    return 0;
}

int maxAreaRectangleMatrix(int a[][4],int n,int m){

    int maxArea;
    int histo[m];
    int area;

    for(int i=0;i<m;i++) //for initializing the histo
    histo[i]=a[0][i];
    maxArea = maxAreaHistogram(histo,m);

    for(int i=1;i<n;i++){

        for(int j=0;j<m;j++){
            
            if(a[i][j]==1)
            {
                histo[j]=histo[j]+a[i][j];
            }
            else
            {
                histo[j]=0;
            }
        }
        area = maxAreaHistogram(histo, m);
        maxArea = area > maxArea ? area : maxArea;
    }
    return maxArea;
}

//working like gas
int maxAreaHistogram(int a[],int size){
    stack<int> s; //stack
    int left[size];//to store left limit
    int right[size]; //to store right limit
    int tp; //for top element

    //int a[] = {6,2,5,4,5,1,6};
    //left limit
    for(int i=0;i<size;i++){

        while(!s.empty()&&a[s.top()]>=a[i]){//stops when element is small or stck is empty
            s.pop();
        }
 
        if (s.empty())//if stack is empty
        {
            s.push(i);
            left[i] = 0;
        }

        else//if we found the left limit of the element
        {
            left[i]=s.top()+1;
            s.push(i);
        }
        
    }
    while(!s.empty()) s.pop();

    //for right limit
    for(int i=size-1;i>=0;i--){
        while(!s.empty()&& a[ s.top() ]>=a[i])
        {
            s.pop();
        }
        if(s.empty()){
            right[i] = size-1;
            s.push(i);
        }
        else
        {
            right[i]=s.top()-1;
            s.push(i);
        }

    }

    int maxArea=(right[0]-left[0]+1)*a[0]; //initializing the max value
    int area;
    for(int i=1;i<size;i++){
        area = (right[i]-left[i]+1)*a[i];
        maxArea=area>maxArea?area:maxArea;
    }
    return maxArea;
}

