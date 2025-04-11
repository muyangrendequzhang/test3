#include<queue>
#include<iostream>
using namespace std;
#define int long long
typedef pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>> pii;
const int N=1e3+10;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int a[N][N];
int n,m,k;
queue<pii>q;
void bfs()
{
    q.push({{1,1},{{1,1},{0,0}}});//初始位置在1,1，并且所在的值为1，且这是第一个1,其父节点为11
    while(!q.empty())
    {
        
        int x=q.front().first.first;
        int y=q.front().first.second;
        int v=q.front().second.first.first;//value;
        int len=q.front().second.first.second;
        int fx=q.front().second.second.first;
        int fy=q.front().second.second.second;
        q.pop();
        if(x==n&&y==m)
        {
            cout<<len-1;
            return;
        }
        len++;
        for(int i=0;i<4;i++)
        {
           
            int tx=x+dx[i];
            int ty=y+dy[i];
            
            v=((len-1)/k)%2+1;
            if(tx==fx&&ty==fy)continue;//父节点跳过
            if(v==a[tx][ty])//能走
            {
                q.push({{tx,ty},{{v,len},{x,y}}});
            }
        }
    }
}
signed main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            if(t=='A')a[i][j]=1;
            if(t=='B')a[i][j]=2;
        }
    }
    bfs();
    cout<<-1;
    return 0;
}