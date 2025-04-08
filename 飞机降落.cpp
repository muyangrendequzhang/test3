#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N=15;
int l[N];
int d[N];
int t[N];
int st[N];//判断当前飞机的状态
int a[N];//记录顺序
int T,n;
bool check=false;
void dfs(int num)
{
    if(check==true)
    {
        return;
    }
    if(num==n+1)//a[n]里面存储了飞行次序
    {
        check=true;
        int cnt=t[a[1]]+l[a[1]];//到达加降飞时间
        for(int i=2;i<=n;i++)
        {
            if(cnt>t[a[i]]+d[a[i]])
            {
                check=false;
                break;
            }
            else
            {
                cnt=max(cnt,t[a[i]])+l[a[i]];
            }
           
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(st[i]==0)
        {
            st[i]=1;
            a[num]=i;
            dfs(num+1);
            st[i]=0;
        }
    }
    return;
}
signed main()
{
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>t[i]>>d[i]>>l[i];
        }
        dfs(1);
        if(check)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        check=false;
        memset(st,0,sizeof(st));
    }

    return 0;
}