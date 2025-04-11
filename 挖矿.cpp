#include<iostream>
using namespace std;
#define int long long
const int N=1e6+10;
int l[N];
int r[N];
int n,m;
int f=0;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        if(t==0)
        {
            f++;
        }
        if(t<0)
        {
            l[-t]++;
        }
        else if(t>0)
        {
            r[t]++;
        }
    }//记录什么位置上是有矿的
    l[0]=r[0]=0;

    for(int i=1;i<=m;i++)
    {
        l[i]+=l[i-1];
        r[i]+=r[i-1];
    }
    int res=0;
    for(int i=1;i<=m;i++)//先向左或者右走i个位置
    {
        int sum1=l[i];//先把往左的能拿的都拿了
        if(m-i*2>0)
        {
            sum1+=r[m-2*i];
        }
        int sum2=r[i];
        if(m-i*2>0)
        {
            sum2+=l[m-2*i];
        }
        res=max(res,max(sum1,sum2));
    }
    res+=f;
    cout<<res;
    return 0;
}

   