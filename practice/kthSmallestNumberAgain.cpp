#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int test;
    // cout<<"taking test"<<endl;

    cin>>test;
    while(test--)
    {
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> vep;
        // cout << "inputing vep" << endl;
        for(int i=0;i<n;i++)
        {   
            int a,b;
            cin>>a>>b;
            vep.push_back({a,b});
        }
        // cout << "sorting" << endl;
        sort(vep.begin(),vep.end());
        //merging
        // cout << "merging" << endl;
        int index = 0;
        for(int i=1;i<n;i++)
        {
            if(vep[index].second >= vep[i].first)
            {
                vep[index].second = max(vep[i].second,vep[index].second);
            }
            else
            {
                index++;
                vep[index] = vep[i];
            }
        }
        //taking querires
        // cout << "taking queries" <<index <<endl;
        while(q--)
        {
            int k;
            cin>>k;
            int ans = -1;
            for(int i=0;i<=index;i++)
            {
                if(vep[i].second-vep[i].first >= k )
                {
                    ans = vep[i].first+k -1;
                    break;
                }
                else
                {
                    k = k - (vep[i].second - vep[i].first + 1);
                }
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}

