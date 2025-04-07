// dp经典题
#include <iostream>
using namespace std;
int n, m, x1;
int y2;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long dp[25][25];
bool check(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        if ((x==x1&&y==y2)||(x == x1 + dx[i] && y == y2 + dy[i]) || x > n || y > m || x < 0 || y < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
   
    cin >> n >> m >> x1 >> y2;
    dp[0][0]=1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // 跳过起点和马控制的位置
            if ((i == 0 && j == 0) || !check(i,j)) continue;
            
            // 状态转移：从上面或左边走过来
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout<<dp[n][m];
    return 0;
}