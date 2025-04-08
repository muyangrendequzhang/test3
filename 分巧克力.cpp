#include<iostream>
using namespace std;
#define int long long
const int N=1e5+100;
int h[N],w[N];
int n,k;
bool check(int mid)
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        num=num+(h[i]/mid)*(w[i]/mid);
    }
    return num>=k;//true的情况为巧克力分太小了
}
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i]>>w[i];
    }
    int l=0,r=1e5;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l;
    return 0;
}