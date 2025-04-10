#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
// 删除这行: #define int long long
const int N=1e3+10;
int n,k;
int a[N][N];
bool vis[N][N][105]; // 改用bool类型节省内存
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

struct Node {
    int x, y, st, len;  // 坐标，无敌时间，步数
    Node(int _x, int _y, int _st, int _len): x(_x), y(_y), st(_st), len(_len) {}
};

void bfs()
{   
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(1, 1, 0, 0));
    vis[1][1][0] = true; // 标记起点已访问
    
    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();
        
        if(cur.x == n && cur.y == n)
        {
            cout << cur.len;
            return;
        }
        
        for(int i=0; i<4; i++)
        {
            int tx = cur.x + dx[i];
            int ty = cur.y + dy[i];
            
            // 边界检查
            if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
            
            int len1 = cur.len + 1;
            int st1 = max(cur.st - 1, 0);
            
            // 不可通行的情况
            if(a[tx][ty] == 3 || (a[tx][ty] == 2 && st1 == 0) || a[tx][ty] == 0)
                continue;
            
            // 获得无敌状态
            if(a[tx][ty] == 4)
                st1 = k;
                
            // 如果这个状态已经访问过，跳过
            if(vis[tx][ty][st1])
                continue;
                
            vis[tx][ty][st1] = true;
            q.push(Node(tx, ty, st1, len1));
        }
    }
    
    cout << -1; // 如果无法到达终点
}

int main() // 改为普通的main函数
{
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char t;
            cin >> t;
            if(t == '.') a[i][j] = 1; // 可以通行
            else if(t == 'X') a[i][j] = 2; // 陷阱
            else if(t == '#') a[i][j] = 3; // 不可走
            else if(t == '%') a[i][j] = 4; // 无敌状态
            else a[i][j] = 0; // 未定义状态
        }
    }
    bfs();
    return 0;
}