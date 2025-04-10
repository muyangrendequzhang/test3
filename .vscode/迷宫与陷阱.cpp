#include<iostream>
#include<queue>
using namespace std;
#define int long long
const int N=1e3+10;
int n,k;
int a[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef pair<pair<int,int>,pair<int,int>> pii;//三个i分别表示坐标xy和无敌时间t
queue<pii>q;
void bfs()
{   
    q.push({{1,1},{0,0}});//推入队内起始位置，没有无敌,走了0步
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int st=q.front().second.first;
        int len=q.front().second.second;
        if(x==n&&y==n)
        {
            cout<<len;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            int len1=len+1;
            int tx=x+dx[i];
            int ty=y+dy[i];
            int st1=max(st-1,(int)0);
            if(a[tx][ty]==3||(a[tx][ty]==2&&st1==0)||a[tx][ty]==0)
            {
                continue;
            }//如果是不可走，或者是陷阱但是没有无敌状态，那就结束
            else if(a[tx][ty]==1||(a[tx][ty]==2&&st1>0))
            {
                q.push({{tx,ty},{st1,len1}});
            }//可走，有无敌状态的陷阱
            else
            {
                st1=k;//补充无敌状态
                q.push({{tx,ty},{st1,len1}});
            }
        }
    }
}
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char t;
            cin>>t;
            if(t='.')a[i][j]=1;//1是可以通行
            if(t='X')a[i][j]=2;//2是陷阱
            if(t='#')a[i][j]=3;//3是不可走
            if(t='%')a[i][j]=4;//4是无敌状态
        }
    }
    bfs();
    return 0;
}