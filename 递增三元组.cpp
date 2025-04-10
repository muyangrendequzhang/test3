#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+100;
int n;
int a[N],b[N],c[N];
// void solve()//暴力解，能过百分之72
// {
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             for(int k=1;k<=n;k++)
//             {
//                 if(a[i]<b[j]&&b[j]<c[k])
//                 {
//                     ans++;
//                 }
//             }
//         }
//     }
//     cout<<ans;
// }
void solve()
{
    int ans=0;
    sort(a+1,a+n+1);
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++)
    {
        int l=0,r=n+1;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
           
            if(a[mid]>=b[i])
            {
                r=mid;
            }
            else
            {
                l=mid;
            }

        }
        int a=l;
        
        // cout<<l<<" "<<r;取l
        l=0,r=n+1;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            
            if(c[mid]<=b[i])
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        int b=n-l;
      
       ans+=a*b;
    }
    cout<<ans;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    solve();
    return 0;
}