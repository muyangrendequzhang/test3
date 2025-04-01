#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
struct node
{ 
    int x;
    int y;
};//记录我们点所在的位置
int n,m,x,y;
int dis[500][500];//记录距离
int vis[500][500];//记录是否走过了
bool check(int mx,int my)
{
    if(mx<=n&&my<=m&&mx>0&&my>0&&vis[mx][my]==0)
    {
        return true;
    }//合法性判断
    else
    {
        return false;
    }
}
int dx[8]={2,2,1,-1,-2,-2,-1,1};
int dy[8]={1,-1,-2,-2,-1,1,2,2};//x,y的走法


int main()
{
    cin>>n>>m>>x>>y;//n,m代表大小，x,y代表起始点
    memset(dis,-1,sizeof(dis));//初始化为负一
    dis[x][y]=0;
    vis[x][y]=1;//初始值为0，设置为1是走过
    queue<pii>q;
    q.push({x,y});//第一个进队
    while(!q.empty())
    {
        int x1=q.front().first;
        int y1=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x2=x1+dx[i];
            int y2=y1+dy[i];
            if(!check(x2,y2))
            {
                continue;//不符合合理性判断的，直接退出
            }
            dis[x2][y2]=dis[x1][y1]+1;//处理数据
            vis[x2][y2]=1;//设定为走过了
            q.push({x2,y2});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

}