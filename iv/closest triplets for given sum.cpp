fun()
{
    if(A.size() < 3){
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int i = 0;
    int sum, minDiff = INT_MAX;
    
    while(i < A.size()-2){
        int left = i+1;
        int right = A.size()-1;
        while(right > left){
            int temp = A[i]+A[left]+A[right];
            int diff = abs(temp-B);
            if(diff == 0){
                return B;
            }
            if(diff < minDiff){
                minDiff = diff;
                sum = temp;
            }
            if(temp < B){
                left++;
            }
            else{
                right--;
            }
        }
        i++;
    }
    
    return sum;
}

int Solution::threeSumClosest(vector<int> &a, int b)
{
    sort(a.begin(),a.end());

    int size = a.size();
    int min_diff = INT_MAX;
    int best_sum;

    if(size==3)
    return a[0]+a[1]+a[2];

    if(size<3)
    return 0;

    cout<<size<<endl;

    int i=0;

    while(i<a.size()-2)
    {
        if(i>size-2)
        break;
        
        int left = i+1;
        int right = size-1;

        cout<<i<<" "<<best_sum<<endl;

        while(left<right)
        {
            int curr_sum = a[left]+a[i]+a[right];

            if(curr_sum==b)
            return curr_sum;

            if(abs(curr_sum-b)<min_diff)
            {
                min_diff = abs(curr_sum-b);
                best_sum = curr_sum;
            }

            if(curr_sum>b)
            right--;

            else
            left++;
        }

        i++;
    }

    best_sum;
}
