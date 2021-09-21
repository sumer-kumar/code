//https://drive.google.com/file/d/1YeUSUiSMcjjvANSCDb8pCVkxsD-xe_e0/view


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
ll n;
vector<long double> c_x(200);
vector<long double> c_y(200);
void run()
{
   fast;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt","w",stdout);
   #endif // ONLINE_JUDGE
}
ll find_min(long double a,long double b)
{
  ll sumation=0;
   for(int i=0;i<n;i++)
      {


          if(a==c_x[i]&&b==c_y[i])
          sumation+=0;
          else if(a==c_x[i]||b==c_y[i])
          sumation+=1;
          else if(abs(a-c_x[i])==abs(b-c_y[i]))
          sumation+=1;
          else
          sumation+=2;


      }

      return sumation;
}
int main()
{
    run();

    ll t;
    cin>>t;
    while(t--)
    {
      cin>>n;
      for(int i=0;i<n;i++)
      {
      cin>>c_x[i];
      }
      for(int i=0;i<n;i++)
      {
      cin>>c_y[i];
      }
      for(int o=0;o<100;o++)
      {
        //just for fun
        ll pqr=o;
      }
      ll min_op=1e18;
      long double a,b;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          a=c_x[i];
          b=c_y[j];

          min_op=min(min_op,find_min(a,b));

          a=0.5*(c_y[i]+c_x[i]+c_y[j]-c_x[j]);
          a=0.5*(c_y[i]+c_x[i]-(c_y[j]-c_x[j]));

          min_op=min(min_op,find_min(a,b));

          b=c_y[i];
          a=c_y[j]+c_x[j]-b;

          min_op=min(min_op,find_min(a,b));

          a=b-(c_y[j]-c_x[j]);

          min_op=min(min_op,find_min(a,b));

          a=c_x[i];
          b=c_y[j]-c_x[j]+b;

          min_op=min(min_op,find_min(a,b));

          b=c_y[j]+c_x[j]-b;

          min_op=min(min_op,find_min(a,b));

          a=0.5*(c_x[i]+c_x[j]);
          b=0.5*(c_y[i]+c_y[j]);

          min_op=min(min_op,find_min(a,b));


        }
      }

    cout<<min_op<<endl;
    for(int i=0;i<200;i++)
    {
      c_x[i]=0;
      c_y[i]=0;
    }



    }
}
