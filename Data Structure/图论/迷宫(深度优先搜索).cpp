#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int res=0;
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
int s_x,s_y,e_x,e_y;
int n,m,t;
void dfs(int x,int y){
    if(x==e_x&&y==e_y)
    {
        res++;
        return;
    }
    for(int i=1;i<=4;++i)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<=n&&ty<=m&&tx>=1&&ty>=1&&a[tx][ty]==0)
        {
            a[tx][ty]=1;
            dfs(tx,ty);
            a[tx][ty]=0;
        }
    }
}
int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=0;
        }
    }
    cin>>s_x>>s_y>>e_x>>e_y;
    for(int i=0;i<t;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    a[s_x][s_y]=1;
    dfs(s_x,s_y);
    cout<<res;
}