#include<iostream>
using namespace std;
#define int long long
int n,m;
const int N=1e5+100;
int a[N],b[N];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    int len=max(n,m);
    int res=0;
    for(int j=1,i=1;i<=len,j<=len;)
    {
        if(a[i]<b[j])
        {
            res++;
            a[i+1]+=a[i];
            i++;
        }
        else if(a[i]>b[j])
        {
            res++;
            b[j+1]+=b[j];
            j++;
        }
        else
        {
            i++;
            j++;
        }
        if(i==len||j==len)
        {
            break;
        }
    }
    cout<<res;
    return 0;
}