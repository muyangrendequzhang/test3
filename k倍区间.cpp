#include<iostream>
using namespace std;
#define int long long
int n,k;
const int N=1e5+1;
int a[N];
int s[N];
int js[N];
signed main()
{
    cin>>n>>k;
    js[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=(a[i]+s[i-1])%k;
        js[s[i]]++;
    }
    int res=0;
    for(int i=0;i<=n;i++)
    {
        res+=(js[i]*(js[i]-1)/2);
    }
    cout<<res;
    return 0;
}