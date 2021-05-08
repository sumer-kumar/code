#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int *a, int n);


int main(){
    int b[] = {3, - 7, - 9, 2 ,- 7, 5 ,- 4, - 8};

    cout<<maxProduct(b,sizeof(b)/sizeof(b[0]));


    return 0;
}

long long maxProduct(int *arr, int n)
{
    long long max_ending_here = 1;
    long long min_ending_here = 1;

    long long max_so_far = 0;
    long long flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i],(long long) 1);
            flag = 1;
        }

        else if (arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        else
        {
            long long temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i],(long long) 1);
            min_ending_here = temp * arr[i];
        }
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    if (flag == 0 && max_so_far == 0)
        return 0;
    return max_so_far;
}